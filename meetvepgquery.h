#ifndef MEETVEPGQUERY_H
#define MEETVEPGQUERY_H

#include <QObject>

#include "meetvchannel.h"
#include "meetveventmodel.h"
#include "QHtsp/qhtspepgquery.h"

class MeeTvEpgQuery : public QHtspEpgQuery
{
    Q_OBJECT
    Q_PROPERTY(MeeTvEventModel *eventsModel READ eventsModel)
    Q_PROPERTY(MeeTvChannel *channel READ channel WRITE setChannel)
public:
    explicit MeeTvEpgQuery(QObject *parent = 0);
    MeeTvEpgQuery(const QHtspEpgQuery& epgQuery, QObject *parent = 0);

    MeeTvChannel *channel();
    MeeTvEventModel *eventsModel();

    void setChannel(MeeTvChannel *channel);

private:
    MeeTvChannel *m_channel;
    MeeTvEventModel *m_eventModel;
    
};

#endif // MEETVEPGQUERY_H
