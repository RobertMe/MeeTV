#ifndef MEETV_H
#define MEETV_H

#include <QObject>

#include "qmlapplicationviewer.h"

#include "./QHtsp/qhtsp.h"
#include "meetvchannelmodel.h"
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
    void _initHtsp();
    void _initViewer();
    void _registerTypes();

    QmlApplicationViewer m_viewer;

    QHtsp *m_htsp;
    MeeTvChannelModel *m_channelModel;
    MeeTvEventModel *m_eventModel;
    MeeTvTagModel *m_tagModel;

};

#endif // MEETV_H
