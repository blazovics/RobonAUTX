#include "Event.h"

quint32 Event::getEventID() const
{
    return eventID;
}

void Event::setEventID(const quint32 &value)
{
    eventID = value;
}

quint32 Event::getRawDataSize() const
{
    return  quint32(rawData.size());
}

QByteArray Event::getRawData() const
{
    return rawData;
}

void Event::setRawData(const QByteArray &value)
{
    rawData = value;
}

Event::Event():eventID(0)
{

}

Event::Event(quint32 eventID, const QByteArray &rawData):eventID(eventID),rawData(rawData)
{

}
