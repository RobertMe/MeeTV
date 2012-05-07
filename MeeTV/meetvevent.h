#ifndef MEETVEVENT_H
#define MEETVEVENT_H

#include <QObject>

#include "meetvhtsp.h"
#include "../QHtsp/qhtspevent.h"

class MeeTvEvent : public QHtspEvent
{
    Q_OBJECT
    Q_PROPERTY(QString startDate READ startDate)
public:
    explicit MeeTvEvent(QObject *parent = 0);
    MeeTvEvent(const QHtspEvent& event, QObject *parent = 0);
    
    QString startDate();

signals:
    
public slots:
    
};

#endif // MEETVEVENT_H
