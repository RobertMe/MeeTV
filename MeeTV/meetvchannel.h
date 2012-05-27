#ifndef MEETVCHANNEL_H
#define MEETVCHANNEL_H

#include <QObject>

#include "meetveventmodel.h"
#include "../QHtsp/qhtspchannel.h"

class MeeTvService;
class MeeTvChannel : public QHtspChannel
{
    Q_OBJECT
    Q_PROPERTY(MeeTvEventModel *eventsModel READ eventsModel)
    Q_PROPERTY(MeeTvService *service READ service WRITE setService NOTIFY serviceChanged)
    Q_PROPERTY(QObject *parent READ parent WRITE setParent)

public:
    explicit MeeTvChannel(QObject *parent = 0);
    MeeTvChannel(const QHtspChannel& channel, QObject *parent = 0);

    MeeTvEventModel *eventsModel();
    MeeTvService *service();

    void setService(MeeTvService *service);

signals:
    void serviceChanged();

private:
    MeeTvEventModel *m_eventModel;
    MeeTvService *m_meetvService;

};

#endif // MEETVCHANNEL_H
