#ifndef MEETV_H
#define MEETV_H

#include <QObject>
#include <QString>

#include "qmlapplicationviewer.h"

#include "./QHtsp/qhtsp.h"
#include "meetvchannelmodel.h"
#include "meetvdvrentrymodel.h"
#include "meetveventmodel.h"
#include "meetvsettings.h"
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
    MeeTvSettings *m_settings;

    QHtsp *m_htsp;
    MeeTvChannelModel *m_channelModel;
    MeeTvDvrEntryModel *m_dvrEntriesModel;
    MeeTvEventModel *m_eventModel;
    MeeTvTagModel *m_tagModel;

private slots:
    void _connected();
};

#endif // MEETV_H
