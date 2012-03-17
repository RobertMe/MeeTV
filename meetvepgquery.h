#ifndef MEETVEPGQUERY_H
#define MEETVEPGQUERY_H

#include <QObject>

#include "QHtsp/qhtspepgquery.h"

class MeeTvEpgQuery : public QHtspEpgQuery
{
    Q_OBJECT
public:
    explicit MeeTvEpgQuery(QObject *parent = 0);
    MeeTvEpgQuery(const QHtspEpgQuery& epgQuery, QObject *parent = 0);
    
};

#endif // MEETVEPGQUERY_H
