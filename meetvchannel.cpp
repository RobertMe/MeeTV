#include "meetvchannel.h"

#include "meetvhtsp.h"

MeeTvChannel::MeeTvChannel(QObject *parent) :
    QHtspChannel(MeeTvHtsp::instance(), parent), m_eventModel(0)
{
}

MeeTvChannel::MeeTvChannel(const QHtspChannel& channel, QObject *parent) :
    QHtspChannel(channel, parent)
{
}

MeeTvEventModel *MeeTvChannel::eventsModel()
{
    if(!m_eventModel)
        m_eventModel = new MeeTvEventModel(events());

    return m_eventModel;
}
