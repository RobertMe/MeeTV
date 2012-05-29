/*
 *  Copyright (C) 2012 Robert Meijers
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "meetvsettingsgconf.h"

#include <QDebug>
#include <QDBusMessage>
#include <QDBusConnection>

MeeTvSettingsGConf::MeeTvSettingsGConf(QObject *parent)
    : MeeTvSettings(parent), m_hostName("/apps/ControlPanel/MeeTV/Hostname"), m_password("/apps/ControlPanel/MeeTV/Password"),
      m_port("/apps/ControlPanel/MeeTV/Port"), m_username("/apps/ControlPanel/MeeTV/Username")
{
    connect(&m_hostName, SIGNAL(valueChanged()), this, SIGNAL(hostnameChanged()));
    connect(&m_password, SIGNAL(valueChanged()), this, SIGNAL(passwordChanged()));
    connect(&m_port, SIGNAL(valueChanged()), this, SIGNAL(portChanged()));
    connect(&m_username, SIGNAL(valueChanged()), this, SIGNAL(usernameChanged()));
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
