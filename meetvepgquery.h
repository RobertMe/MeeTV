#ifndef MEETVEPGQUERY_H
#define MEETVEPGQUERY_H

#include <QObject>

#include "meetveventmodel.h"
#include "QHtsp/qhtspepgquery.h"

class MeeTvEpgQuery : public QHtspEpgQuery
{
    Q_OBJECT
    Q_PROPERTY(MeeTvEventModel *eventsModel READ eventsModel)
public:
    explicit MeeTvEpgQuery(QObject *parent = 0);
    MeeTvEpgQuery(const QHtspEpgQuery& epgQuery, QObject *parent = 0);

    MeeTvEventModel *eventsModel();

private:
    MeeTvEventModel *m_eventModel;
    
};

#endif // MEETVEPGQUERY_H
