#include "meetvchannel.h"

#include "meetvhtsp.h"

MeeTvChannel::MeeTvChannel(QObject *parent) :
    QHtspChannel(MeeTvHtsp::instance(), parent)
{
}

MeeTvChannel::MeeTvChannel(const QHtspChannel& channel, QObject *parent) :
    QHtspChannel(channel, parent)
{
}

