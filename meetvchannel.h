#ifndef MEETVCHANNEL_H
#define MEETVCHANNEL_H

#include <QObject>

#include "QHtsp/qhtspchannel.h"

class MeeTvChannel : public QHtspChannel
{
    Q_OBJECT
public:
    explicit MeeTvChannel(QObject *parent = 0);
    MeeTvChannel(const QHtspChannel& channel, QObject *parent = 0);
};

#endif // MEETVCHANNEL_H
