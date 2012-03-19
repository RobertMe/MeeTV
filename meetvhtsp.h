#ifndef MEETVHTSP_H
#define MEETVHTSP_H

#include <QMutex>
#include <QObject>

#include "meetvdvrentry.h"
#include "QHtsp/qhtsp.h"

class MeeTvHtsp : public QHtsp
{
    Q_OBJECT

public:
    static MeeTvHtsp *instance();

signals:
    void dvrEntryAdded(MeeTvDvrEntry *dvrEntry);

private:
    MeeTvHtsp(QObject *parent = 0);
    MeeTvHtsp& operator=(const MeeTvHtsp &);
    
    static MeeTvHtsp *m_instance;
    static QMutex m_mutex;

private slots:
    void emitDvrEntryAdded(QHtspDvrEntry *dvrEntry);
};

#endif // MEETVHTSP_H
