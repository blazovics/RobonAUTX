/**
 * Project RobonAUT
 * @author László Blázovics
 * @version 0.9
 */


#include "SocketConnection.h"
#include <QDataStream>
#include <stdexcept>

/**
 * SocketConnection implementation
 */


/**
 * @param event
 */
ISocketConnectionDelegate *SocketConnection::getSocketDelegate() const
{
    return socketDelegate;
}

void SocketConnection::setSocketDelegate(ISocketConnectionDelegate *value)
{
    socketDelegate = value;
}

QTcpSocket *SocketConnection::GetActiveSocket() const
{
    return activeSocket;
}

SocketConnection::SocketConnection(QTcpSocket *socket, ISocketConnectionDelegate *delegate, QObject *parent):QObject (parent),activeSocket(socket),pendingMessageSize(0),socketDelegate(delegate)
{
    if(activeSocket == nullptr)
    {
        //TODO: easylogging
        qDebug()<<"No active socket in SocketConnection";
    }
    if(socketDelegate == nullptr)
    {
        //TODO: easylogging
        qDebug()<<"No socket delegate in SocketConnection";
    }

    bool connected[3];

    connected[0] = connect(activeSocket,SIGNAL(readyRead()),this,SLOT(DataReceived()));
    connected[1] = connect(activeSocket,SIGNAL(disconnected()),this,SLOT(SocketDisconnected()));
    connected[2] = connect(activeSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(SocketErrorOccured(QAbstractSocket::SocketError)));

    for (int i=0; i < 3; i++) {
        if(!connected[i])
        {
            //TODO: EasyLogging
            qDebug()<<"Socket Connection - signal-slot connection failed: " << i;
        }
    }
}

SocketConnection::~SocketConnection()
{

}

void SocketConnection::SendEvent(const Event &event) {
    QDataStream out(&this->outputBuffer,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);
    out<<sizeof(quint32) + sizeof (quint32) + event.getRawDataSize();
    out<<event.getEventID();
    int bytesWrittenToBuffer = out.writeRawData(event.getRawData().data(), int(event.getRawDataSize()));

    if(bytesWrittenToBuffer != int(event.getRawDataSize()))
    {
        qDebug()<<"SendEvent error";
    }

    qint64 bytesWritten = activeSocket->write(this->outputBuffer);
    if(bytesWritten != -1)
    {
        this->outputBuffer.remove(0,int(bytesWritten));
    }
}

void SocketConnection::DataReceived()
{
    this->inputBuffer.append(activeSocket->readAll());
    this->processInputBuffer();
}

void SocketConnection::SocketDisconnected()
{
    socketDelegate->SocketDisconnected(this->activeSocket);
}

void SocketConnection::SocketErrorOccured(QAbstractSocket::SocketError socketError)
{
    //TODO: EasyLogging
    qDebug()<<socketError;

    socketDelegate->SocketError(this->activeSocket);
}

void SocketConnection::extractEventFromBuffer()
{
    QDataStream in(&this->inputBuffer,QIODevice::ReadOnly);

    quint32 messageID;
    in >> messageID;
    this->inputBuffer.remove(0,sizeof (quint32));

    int rawDataLength = int(pendingMessageSize) - int(sizeof (quint32));

    if(rawDataLength < 0)
    {
        throw std::length_error("The lenght of raw data is negative!");
    }

    QByteArray data;
    data.resize(rawDataLength);

    int bytesReadFromBuffer = in.readRawData(data.data(),rawDataLength);
    this->inputBuffer.remove(0,rawDataLength);

    if(bytesReadFromBuffer != int(rawDataLength))
    {
        throw std::length_error("The lenght of raw data is not equal the read data!");
    }

    pendingMessageSize = 0;

    Event newEvent(messageID,data);

    this->socketDelegate->EventReceived(newEvent);
}

void SocketConnection::processInputBuffer()
{
    if(pendingMessageSize > 0)
    {
        if(inputBuffer.size() < int(pendingMessageSize))
        {
            return;
        }
        else
        {
            extractEventFromBuffer();
            processInputBuffer();
        }
    }
    else
    {
        if(inputBuffer.size() < 8)
        {
            //until both the size and the id is known, we cannot process the data
            return;
        }
        else
        {
            QDataStream in(&this->inputBuffer,QIODevice::ReadOnly);
            in >> pendingMessageSize;
            pendingMessageSize -= sizeof (quint32);
            this->inputBuffer.remove(0,sizeof (quint32));

            if(inputBuffer.size() < int(pendingMessageSize))
            {
                return;
            }
            else
            {
                extractEventFromBuffer();
                processInputBuffer();
            }
        }
    }
}

