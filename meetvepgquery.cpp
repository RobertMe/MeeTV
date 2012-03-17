#include "meetvepgquery.h"

#include "meetvhtsp.h"

MeeTvEpgQuery::MeeTvEpgQuery(QObject *parent) :
    QHtspEpgQuery(MeeTvHtsp::instance(), parent), m_eventModel(0)
{
}

MeeTvEpgQuery::MeeTvEpgQuery(const QHtspEpgQuery& epgQuery, QObject *parent) :
    QHtspEpgQuery(epgQuery, parent), m_eventModel(0)
{
}

MeeTvEventModel *MeeTvEpgQuery::eventsModel()
{
    if(!m_eventModel)
        m_eventModel = new MeeTvEventModel(events());

    return m_eventModel;
}
