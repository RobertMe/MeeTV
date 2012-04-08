#include "meetvsettingsgconf.h"

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
