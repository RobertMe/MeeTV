#include "meetv.h"

#include <QtDeclarative>
#include <QDeclarativeContext>

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
    m_htsp = new QHtsp();
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
    qmlRegisterType<QHtspTag>("Htsp", 1, 0, "Tag");
    qmlRegisterType<QHtspChannel>("Htsp", 1, 0, "Channel");
    qmlRegisterType<QHtspEvent>("Htsp", 1, 0, "Event");
    qmlRegisterType<QHtspEventModel>("Htsp", 1, 0, "EventModel");
    qmlRegisterType<QHtspChannelModel>("Htsp", 1, 0, "ChannelModel");
}
