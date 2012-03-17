#ifndef MEETVEVENT_H
#define MEETVEVENT_H

#include <QObject>

#include "meetvhtsp.h"
#include "QHtsp/qhtspevent.h"

class MeeTvEvent : public QHtspEvent
{
    Q_OBJECT
public:
    explicit MeeTvEvent(QObject *parent = 0);
    MeeTvEvent(const QHtspEvent& event, QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MEETVEVENT_H
