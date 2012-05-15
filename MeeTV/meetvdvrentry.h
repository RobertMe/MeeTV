#ifndef MEETVDVRENTRY_H
#define MEETVDVRENTRY_H

#include <QObject>

#include "../QHtsp/qhtspdvrentry.h"

class MeeTvDvrEntry : public QHtspDvrEntry
{
    Q_OBJECT
    Q_PROPERTY(QObject *parent READ parent WRITE setParent)

public:
    explicit MeeTvDvrEntry(QObject *parent = 0);
    MeeTvDvrEntry(const QHtspDvrEntry &dvrEntry, QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MEETVDVRENTRY_H
