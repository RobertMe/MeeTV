#include "meetv.h"

#ifndef QT_SIMULATOR

#endif

#include <QtDeclarative>
#include <QDeclarativeContext>

#include "meetvchannel.h"
#include "meetvepgquery.h"
#include "meetvevent.h"
#include "meetvmodelhelper.h"
#include "meetvtag.h"

#ifndef QT_SIMULATOR
#include "meetvsettingsgconf.h"
#else
#include "meetvsettingshard.h"
#endif

MeeTv::MeeTv(QObject *parent) :
    QObject(parent)
{
#ifndef QT_SIMULATOR
    m_settings = new MeeTvSettingsGConf(this);
#else
    m_settings = new MeeTvSettingsHard(this);
#endif
    m_active = false;
    m_authenticationSettingsChanged = false;
    m_connecting = false;
    m_connectionSettingsChanged = false;

    connect(m_settings, SIGNAL(hostnameChanged()), this, SLOT(_connectionSettingsChanged()));
    connect(m_settings, SIGNAL(portChanged()), this, SLOT(_connectionSettingsChanged()));
    connect(this, SIGNAL(activeChanged()), this, SLOT(_connectHtsp()));

    connect(m_settings, SIGNAL(passwordChanged()), this, SLOT(_authenticationSettingsChanged()));
    connect(m_settings, SIGNAL(usernameChanged()), this, SLOT(_authenticationSettingsChanged()));

    m_idleTimer.setSingleShot(true);
    m_idleTimer.setMinimumInterval(60);
    m_idleTimer.setMaximumInterval(90);
}

bool MeeTv::active()
{
    return m_active;
}

void MeeTv::setActive(bool active)
{
    if(m_active == active)
        return;

    m_active = active;
    emit activeChanged();
}

void MeeTv::authenticate()
{
    m_authenticationSettingsChanged = false;
    disconnect(this, SIGNAL(activeChanged()), this, SLOT(authenticate()));
    if(!m_settings->hasUsername() || !m_settings->hasPassword())
    {
        m_settings->open();
        return;
    }

    m_htsp->authenticate(m_settings->username(), m_settings->password());
    if(!m_htsp->isSyncCompleted())
        m_htsp->enableAsync();
}

void MeeTv::init()
{
    _registerTypes();
    _initHtsp();
    _initViewer();
#ifdef QT_SIMULATOR
    setActive(true);
#endif
}

void MeeTv::run()
{
    m_viewer.showExpanded();
}

void MeeTv::_authenticationSettingsChanged()
{
    if(m_authenticationSettingsChanged)
        return;

    connect(this, SIGNAL(activeChanged()), this, SLOT(authenticate()));
}

void MeeTv::_connected()
{
    disconnect(m_htsp, SIGNAL(connected()), this, SLOT(_connected()));
    disconnect(this, SIGNAL(activeChanged()), this, SLOT(_connectHtsp()));
    disconnect(m_settings, SIGNAL(hostnameChanged()), this, SLOT(_connectionSettingsChanged()));
    disconnect(m_settings, SIGNAL(portChanged()), this, SLOT(_connectionSettingsChanged()));

    connect(this, SIGNAL(activeChanged()), this, SLOT(_idleHandler()));

    if(m_settings->hasUsername() && m_settings->hasPassword())
        authenticate();
    m_htsp->enableAsync();
}

void MeeTv::_connectError()
{
    m_connecting = false;
}

void MeeTv::_connectHtsp()
{
    if(!active())
        return;

    if(!m_settings->hasHostname() || !m_settings->hasPort())
    {
        m_settings->open();
        return;
    }

    if(m_connecting)
        return;

    connect(m_htsp, SIGNAL(connected()), this, SLOT(_connected()));
    m_htsp->connectToServer("MeeTV", "0.1", 1, m_settings->hostname(), m_settings->port());
    m_connecting = true;
    m_connectionSettingsChanged = false;
}

void MeeTv::_connectionSettingsChanged()
{
    m_connectionSettingsChanged = true;
}

void MeeTv::_idleHandler()
{
    if(active())
    {
        m_idleTimer.stop();
        m_htsp->connectFromIdle();
    }
    else
    {
        m_idleTimer.start();
    }
}

void MeeTv::_initHtsp()
{
    m_htsp = MeeTvHtsp::instance();
    m_dvrEntriesModel = new MeeTvDvrEntryModel(m_htsp->dvrEntries());
    m_eventModel = new MeeTvEventModel(m_htsp->events());
    m_tagModel = new MeeTvTagModel(m_htsp->tags());

    connect(&m_idleTimer, SIGNAL(timeout()), m_htsp, SLOT(disconnectIdle()));
    connect(m_htsp, SIGNAL(connectError()), this, SLOT(_connectError()));
}

void MeeTv::_initViewer()
{
    QDeclarativeContext *context = m_viewer.rootContext();
    context->setContextProperty("dvrEntriesModel", m_dvrEntriesModel);
    context->setContextProperty("htsp", m_htsp);
    context->setContextProperty("meetv", this);
    context->setContextProperty("settings", m_settings);
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
    qmlRegisterType<MeeTvModelHelper>("Htsp", 1, 0, "ModelHelper");
}
