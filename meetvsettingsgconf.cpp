#include "meetvsettingsgconf.h"

#include <QDebug>
#include <QDBusMessage>
#include <QDBusConnection>

MeeTvSettingsGConf::MeeTvSettingsGConf(QObject *parent)
    : MeeTvSettings(parent), m_hostName("/apps/ControlPanel/MeeTV/Hostname"), m_password("/apps/ControlPanel/MeeTV/Password"),
      m_port("/apps/ControlPanel/MeeTV/Port"), m_username("/apps/ControlPanel/MeeTV/Username")
{
}

QString MeeTvSettingsGConf::hostname()
{
    return m_hostName.value().toString();
}

QString MeeTvSettingsGConf::password()
{
    return m_password.value().toString();
}

quint16 MeeTvSettingsGConf::port()
{
    return m_port.value().toInt();
}

QString MeeTvSettingsGConf::username()
{
    return m_username.value().toString();
}

bool MeeTvSettingsGConf::hasHostname()
{
    return m_hostName.value().isValid();
}

bool MeeTvSettingsGConf::hasPassword()
{
    return m_password.value().isValid();
}

bool MeeTvSettingsGConf::hasPort()
{
    return m_port.value().isValid();
}

bool MeeTvSettingsGConf::hasUsername()
{
    return m_username.value().isValid();
}

void MeeTvSettingsGConf::open()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
           "com.nokia.DuiControlPanel",
           "/",
           "com.nokia.DuiControlPanelIf",
           "appletPage");

    QList<QVariant> args;
    args.append(QVariant("MeeTV"));
    message.setArguments(args);

    QDBusConnection bus = QDBusConnection::sessionBus();
    if(bus.isConnected())
        bus.send(message);
}
