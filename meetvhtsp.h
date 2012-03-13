#ifndef MEETVHTSP_H
#define MEETVHTSP_H

#include <QMutex>
#include <QObject>

#include "QHtsp/qhtsp.h"

class MeeTvHtsp : public QHtsp
{
    Q_OBJECT

public:
    static MeeTvHtsp *instance();

private:
    MeeTvHtsp(QObject *parent = 0);
    MeeTvHtsp& operator=(const MeeTvHtsp &);
    

    static MeeTvHtsp *m_instance;
    static QMutex m_mutex;
};

#endif // MEETVHTSP_H
