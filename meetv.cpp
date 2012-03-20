#include "meetv.h"

#ifndef QT_SIMULATOR
#include <gconfitem.h>
#endif

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
#ifndef QT_SIMULATOR
    m_hostName = GConfItem("/apps/ControlPanel/MeeTV/Hostname").value().toString();;
    m_password = GConfItem("/apps/ControlPanel/MeeTV/Password").value().toString();
    m_port = GConfItem("/apps/ControlPanel/MeeTV/Port").value().toInt();
    m_username = GConfItem("/apps/ControlPanel/MeeTV/Username").value().toString();
#else
    m_hostName = "192.168.1.2";
    m_password = "hts";
    m_port = 9982;
    m_username = "hts";
#endif
}

void MeeTv::authenticate()
{
    m_htsp->authenticate(m_username, m_password);
    m_htsp->enableAsync();
}

void MeeTv::init()
{
    _registerTypes();
    _initHtsp();
    _initViewer();
    _connectHtsp();
}

void MeeTv::run()
{
    m_viewer.showExpanded();
}

void MeeTv::_connectHtsp()
{
    connect(m_htsp, SIGNAL(connected()), this, SLOT(authenticate()));
    m_htsp->connectToServer("MeeTV", "0.1", 1, m_hostName, m_port);
}

void MeeTv::_initHtsp()
{
    m_htsp = MeeTvHtsp::instance();
    m_channelModel = new MeeTvChannelModel(m_htsp->channels());
    m_dvrEntriesModel = new MeeTvDvrEntryModel(m_htsp->dvrEntries());
    m_eventModel = new MeeTvEventModel(m_htsp->events());
    m_tagModel = new MeeTvTagModel(m_htsp->tags());
}

void MeeTv::_initViewer()
{

    QDeclarativeContext *context = m_viewer.rootContext();
    context->setContextProperty("channelModel", m_channelModel);
    context->setContextProperty("dvrEntriesModel", m_dvrEntriesModel);
    context->setContextProperty("eventModel", m_eventModel);
    context->setContextProperty("htsp", m_htsp);
    context->setContextProperty("tagModel", m_tagModel);

    m_viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    m_viewer.setMainQmlFile(QLatin1String("qml/MeeTV/main.qml"));
}

void MeeTv::_registerTypes()
{
    qmlRegisterType<MeeTvTag>("Htsp", 1, 0, "Tag");
    qmlRegisterType<MeeTvChannel>("Htsp", 1, 0, "Channel");
    qmlRegisterType<MeeTvDvrEntry>("Htsp", 1, 0, "DvrEntry");
    qmlRegisterType<MeeTvEpgQuery>("Htsp", 1, 0, "EpgQuery");
    qmlRegisterType<MeeTvEvent>("Htsp", 1, 0, "Event");
    qmlRegisterType<MeeTvEventModel>("Htsp", 1, 0, "EventModel");
    qmlRegisterType<MeeTvChannelModel>("Htsp", 1, 0, "ChannelModel");
}
