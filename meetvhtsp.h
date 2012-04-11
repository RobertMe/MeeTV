#ifndef MEETVHTSP_H
#define MEETVHTSP_H

#include <QMutex>
#include <QNetworkSession>
#include <QObject>

#include "meetvdvrentry.h"
#include "QHtsp/qhtsp.h"

class MeeTvHtsp : public QHtsp
{
    Q_OBJECT

public:
    void connectToServer(QString clientName, QString clientVersion, uint preferredHtspVersion, QString hostName, quint16 port = 9982);

    static MeeTvHtsp *instance();

signals:
    void dvrEntryAdded(MeeTvDvrEntry *dvrEntry);

private:
    MeeTvHtsp(QObject *parent = 0);
    MeeTvHtsp& operator=(const MeeTvHtsp &);

    QNetworkSession *m_session;

    static MeeTvHtsp *m_instance;
    static QMutex m_mutex;

private slots:
    void emitDvrEntryAdded(QHtspDvrEntry *dvrEntry);
};

#endif // MEETVHTSP_H
