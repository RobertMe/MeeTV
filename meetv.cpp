#include "meetv.h"

#include <QtDeclarative>
#include <QDeclarativeContext>

#include "meetvhtsp.h"
#include "meetvchannel.h"
#include "meetvepgquery.h"
#include "meetvevent.h"
#include "meetvtag.h"

MeeTv::MeeTv(QObject *parent) :
    QObject(parent)
{
}

void MeeTv::authenticate()
{
    m_htsp->authenticate("hts", "hts");
    m_htsp->enableAsync();
}

void MeeTv::init()
{
    _registerTypes();
    _initHtsp();
    _initViewer();
}

void MeeTv::run()
{
    m_viewer.showExpanded();
}

void MeeTv::_initHtsp()
{
    m_htsp = MeeTvHtsp::instance();
    m_channelModel = new QHtspChannelModel(m_htsp->channels());
    m_tagModel = new QHtspTagModel(m_htsp->tags());
    m_eventModel = new QHtspEventModel(m_htsp->events());

    connect(m_htsp, SIGNAL(connected()), this, SLOT(authenticate()));
    m_htsp->connectToServer("MeeTV", "0.1", 1, "192.168.1.2");
}

void MeeTv::_initViewer()
{
    m_viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    m_viewer.setMainQmlFile(QLatin1String("qml/MeeTV/main.qml"));

    QDeclarativeContext *context = m_viewer.rootContext();
    context->setContextProperty("tagModel", m_tagModel);
    context->setContextProperty("channelModel", m_channelModel);
    context->setContextProperty("eventModel", m_eventModel);
}

void MeeTv::_registerTypes()
{
    qmlRegisterType<MeeTvTag>("Htsp", 1, 0, "Tag");
    qmlRegisterType<MeeTvChannel>("Htsp", 1, 0, "Channel");
    qmlRegisterType<MeeTvEvent>("Htsp", 1, 0, "Event");
    qmlRegisterType<QHtspEventModel>("Htsp", 1, 0, "EventModel");
    qmlRegisterType<QHtspChannelModel>("Htsp", 1, 0, "ChannelModel");
}
