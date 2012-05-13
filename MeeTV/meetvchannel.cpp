#include "meetvchannel.h"

#include "meetvhtsp.h"
#include "meetvservice.h"

MeeTvChannel::MeeTvChannel(QObject *parent) :
    QHtspChannel(MeeTvHtsp::instance(), parent), m_eventModel(0), m_meetvService(0)
{
}

MeeTvChannel::MeeTvChannel(const QHtspChannel& channel, QObject *parent) :
    QHtspChannel(channel, parent), m_eventModel(0), m_meetvService(0)
{
}

MeeTvEventModel *MeeTvChannel::eventsModel()
{
    if(!m_eventModel)
        m_eventModel = new MeeTvEventModel(events());

    return m_eventModel;
}

MeeTvService *MeeTvChannel::service()
{
    if(!QHtspChannel::service() && m_meetvService)
    {
        delete m_meetvService;
        m_meetvService = 0;
    }
    else
    {
        if(QHtspChannel::service()->name() != m_meetvService->name())
        {
            delete m_meetvService;
            m_meetvService = 0;
        }
        if(QHtspChannel::service() && !m_meetvService)
        {
            m_meetvService = dynamic_cast<MeeTvService*>(QHtspChannel::service());
            if(!m_meetvService)
                m_meetvService = new MeeTvService(*QHtspChannel::service(), this);
        }
    }

    return m_meetvService;
}

void MeeTvChannel::setService(MeeTvService *service)
{
    if(m_meetvService)
        delete m_meetvService;

    m_meetvService = service;
    QHtspChannel::setService(service);
}
