#include "meetvchannel.h"

#include "meetvhtsp.h"

MeeTvChannel::MeeTvChannel(QObject *parent) :
    QHtspChannel(MeeTvHtsp::instance(), parent)
{
}
