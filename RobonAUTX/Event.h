#ifndef EVENT_H
#define EVENT_H

#include <QObject>

class Event
{
    quint32 eventID;
    QByteArray rawData;

public:
    Event();
    Event(quint32 eventID, const QByteArray &rawData);
    quint32 getEventID() const;
    void setEventID(const quint32 &value);
    quint32 getRawDataSize()const;
    QByteArray getRawData() const;
    void setRawData(const QByteArray &value);
};

#endif // EVENT_H
