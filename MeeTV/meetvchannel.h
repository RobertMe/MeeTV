#ifndef MEETVCHANNEL_H
#define MEETVCHANNEL_H

#include <QObject>

#include "meetveventmodel.h"
#include "../QHtsp/qhtspchannel.h"

class MeeTvChannel : public QHtspChannel
{
    Q_OBJECT
    Q_PROPERTY(MeeTvEventModel *eventsModel READ eventsModel)

public:
    explicit MeeTvChannel(QObject *parent = 0);
    MeeTvChannel(const QHtspChannel& channel, QObject *parent = 0);

    MeeTvEventModel *eventsModel();

private:
    MeeTvEventModel *m_eventModel;

};

#endif // MEETVCHANNEL_H
