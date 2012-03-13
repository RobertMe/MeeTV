#include "meetvepgquery.h"

#include "meetvhtsp.h"

MeeTvEpgQuery::MeeTvEpgQuery(QObject *parent) :
    QHtspEpgQuery(MeeTvHtsp::instance(), parent)
{
}
