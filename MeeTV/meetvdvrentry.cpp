#include "meetvdvrentry.h"

#include "meetvhtsp.h"

MeeTvDvrEntry::MeeTvDvrEntry(QObject *parent) :
    QHtspDvrEntry(MeeTvHtsp::instance(), parent)
{
}

MeeTvDvrEntry::MeeTvDvrEntry(const QHtspDvrEntry &dvrEntry, QObject *parent) :
    QHtspDvrEntry(dvrEntry, parent)
{
}
