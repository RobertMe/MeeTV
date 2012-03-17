#ifndef MEETVEPGQUERY_H
#define MEETVEPGQUERY_H

#include <QObject>

#include "meetvchannel.h"
#include "meetveventmodel.h"
#include "meetvtag.h"
#include "QHtsp/qhtspepgquery.h"

class MeeTvEpgQuery : public QHtspEpgQuery
{
    Q_OBJECT
    Q_PROPERTY(MeeTvEventModel *eventsModel READ eventsModel)
    Q_PROPERTY(MeeTvChannel *channel READ channel WRITE setChannel)
    Q_PROPERTY(MeeTvTag *tag READ tag WRITE setTag)
public:
    explicit MeeTvEpgQuery(QObject *parent = 0);
    MeeTvEpgQuery(const QHtspEpgQuery& epgQuery, QObject *parent = 0);

    MeeTvChannel *channel();
    MeeTvEventModel *eventsModel();
    MeeTvTag *tag();

    void setChannel(MeeTvChannel *channel);
    void setTag(MeeTvTag *tag);

private:
    MeeTvChannel *m_channel;
    MeeTvEventModel *m_eventModel;
    MeeTvTag *m_tag;
    
};

#endif // MEETVEPGQUERY_H
