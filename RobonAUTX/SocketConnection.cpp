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
SocketConnection::SocketConnection(QTcpSocket *socket, QObject *parent):QObject (parent)
{
    activeSocket = std::make_unique<QTcpSocket>(socket);

    connect(activeSocket.get(),SIGNAL(readyRead()),this,SLOT(dataReceived()));
}

void SocketConnection::sendEvent(Event event) {
    QDataStream out(&this->outputBuffer,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);
    out<<sizeof(quint32) + event.getRawDataSize();
    out<<event.getEventID();
    int bytesWrittenToBuffer = out.writeRawData(event.getRawData().data(), int(event.getRawDataSize()));

    if(bytesWrittenToBuffer != int(event.getRawDataSize()))
    {
        qDebug()<<"SendEvent error";
    }

    qint64 bytesWritten = activeSocket.get()->write(this->outputBuffer);
    if(bytesWritten != -1)
    {
        this->outputBuffer.remove(0,int(bytesWritten));
    }
}

void SocketConnection::dataReceived()
{
    this->inputBuffer.append(activeSocket.get()->readAll());
    this->processInputBuffer();
}

void SocketConnection::extractEventFromBuffer()
{
    QDataStream in(&this->inputBuffer,QIODevice::ReadOnly);

    quint32 messageID;
    in >> messageID;

    int rawDataLength = int(pendingMessageSize) - int(sizeof (quint32));

    if(rawDataLength < 0)
    {
        throw std::length_error("The lenght of raw data is negative!");
    }

    QByteArray data;
    data.resize(rawDataLength);

    int bytesReadFromBuffer = in.readRawData(data.data(),rawDataLength);

    if(bytesReadFromBuffer != int(pendingMessageSize))
    {
        throw std::length_error("The lenght of raw data is not equal the read data!");
    }

    pendingMessageSize = 0;

    Event newEvent(messageID,data);

    emit eventReceived(newEvent);
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

