#include "meetvservice.h"

MeeTvService::MeeTvService(QHtspChannel *channel, QObject *parent) :
    QHtspService(channel, parent)
{
}

MeeTvService::MeeTvService(QHtspMessage &message, QHtspChannel *channel, QObject *parent) :
    QHtspService(message, channel, parent)
{
}

MeeTvService::MeeTvService(const QHtspService &service, QObject *parent) :
    QHtspService(service, parent)
{
}
