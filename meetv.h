#ifndef MEETV_H
#define MEETV_H

#include <QObject>
#include <QString>

#include "qmlapplicationviewer.h"

#include "./QHtsp/qhtsp.h"
#include "meetvchannelmodel.h"
#include "meetvdvrentrymodel.h"
#include "meetveventmodel.h"
#include "meetvtagmodel.h"

class MeeTv : public QObject
{
    Q_OBJECT
public:
    explicit MeeTv(QObject *parent = 0);

    void init();
    void run();
    
public slots:
    void authenticate();

private:
    void _connectHtsp();
    void _initHtsp();
    void _initViewer();
    void _registerTypes();

    QmlApplicationViewer m_viewer;

    QString m_hostName;
    QString m_password;
    quint16 m_port;
    QString m_username;

    QHtsp *m_htsp;
    MeeTvChannelModel *m_channelModel;
    MeeTvDvrEntryModel *m_dvrEntriesModel;
    MeeTvEventModel *m_eventModel;
    MeeTvTagModel *m_tagModel;

};

#endif // MEETV_H
