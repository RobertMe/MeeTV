#ifndef MEETVHTSP_H
#define MEETVHTSP_H

#include <QMutex>
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
#include <QObject>

#include "meetvdvrentry.h"
#include "QHtsp/qhtsp.h"

class MeeTvHtsp : public QHtsp
{
    Q_OBJECT

public:
    void authenticate(QString username, QString password);
    void connectToServer(QString clientName, QString clientVersion, uint preferredHtspVersion, QString hostName, quint16 port = 9982);
    void enableAsync();

    static MeeTvHtsp *instance();

signals:
    void dvrEntryAdded(MeeTvDvrEntry *dvrEntry);

public slots:
    void connectFromIdle();
    void disconnectIdle();

private:
    MeeTvHtsp(QObject *parent = 0);
    MeeTvHtsp& operator=(const MeeTvHtsp &);

    QNetworkConfigurationManager *m_configurationManager;
    QNetworkSession *m_session;

    bool m_asyncEnabled;
    bool m_authenticated;
    QString m_clientName;
    QString m_clientVersion;
    QString m_hostName;
    QString m_password;
    quint16 m_port;
    QString m_username;
    uint m_preferredHtspVersion;

    QList<int> *m_monitorChannels;
    QList<int> *m_monitorDvrEntries;
    QList<int> *m_monitorTags;


    static MeeTvHtsp *m_instance;
    static QMutex m_mutex;

    void _updateLists();

private slots:
    void emitDvrEntryAdded(QHtspDvrEntry *dvrEntry);
    void _internalConnect();
    void _monitorSync(QString method, QHtspMessage &message);
    void _reconnect();
    void _sessionConnect();
    void _sessionLost();
    void _sessionReconnect();
};

#endif // MEETVHTSP_H
