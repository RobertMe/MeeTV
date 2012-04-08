#ifndef MEETVSETTINGSGCONF_H
#define MEETVSETTINGSGCONF_H

#include <gconfitem.h>
#include <QObject>
#include <QString>

#include "meetvsettings.h"

class MeeTvSettingsGConf : public MeeTvSettings
{
    Q_OBJECT
public:
    explicit MeeTvSettingsGConf(QObject *parent = 0);

    QString hostname();
    QString password();
    quint16 port();
    QString username();

private:
    GConfItem m_hostName;
    GConfItem m_password;
    GConfItem m_port;
    GConfItem m_username;
};

#endif // MEETVSETTINGSGCONF_H
