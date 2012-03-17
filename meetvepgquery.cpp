#include "meetvepgquery.h"

#include "meetvhtsp.h"

MeeTvEpgQuery::MeeTvEpgQuery(QObject *parent) :
    QHtspEpgQuery(MeeTvHtsp::instance(), parent)
{
}

MeeTvEpgQuery::MeeTvEpgQuery(const QHtspEpgQuery& epgQuery, QObject *parent) :
    QHtspEpgQuery(epgQuery, parent)
{
}
