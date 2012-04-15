#ifndef MEETV_H
#define MEETV_H

#include <QObject>
#include <QString>
#include <QtSystemInfo/QSystemAlignedTimer>

QTM_USE_NAMESPACE

#include "qmlapplicationviewer.h"

#include "meetvhtsp.h"
#include "meetvchannelmodel.h"
#include "meetvdvrentrymodel.h"
#include "meetveventmodel.h"
#include "meetvsettings.h"
#include "meetvtagmodel.h"

class MeeTv : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

public:
    explicit MeeTv(QObject *parent = 0);

    bool active();

    void setActive(bool active);

    void init();
    void run();

signals:
    void activeChanged();
    
public slots:
    void authenticate();

private:
    void _initHtsp();
    void _initViewer();
    void _registerTypes();

    bool m_active;
    bool m_authenticationSettingsChanged;
    bool m_connecting;
    bool m_connectionSettingsChanged;
    QmlApplicationViewer m_viewer;
    MeeTvSettings *m_settings;

    QSystemAlignedTimer m_idleTimer;

    MeeTvHtsp *m_htsp;
    MeeTvChannelModel *m_channelModel;
    MeeTvDvrEntryModel *m_dvrEntriesModel;
    MeeTvEventModel *m_eventModel;
    MeeTvTagModel *m_tagModel;

private slots:
    void _authenticationSettingsChanged();
    void _connected();
    void _connectHtsp();
    void _connectionSettingsChanged();
    void _idleHandler();
};

#endif // MEETV_H
