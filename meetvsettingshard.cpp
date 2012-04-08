#include "meetvsettingshard.h"

MeeTvSettingsHard::MeeTvSettingsHard(QObject *parent) :
    MeeTvSettings(parent)
{
}

QString MeeTvSettingsHard::hostname()
{
    return "192.168.1.2";
}

QString MeeTvSettingsHard::password()
{
    return "hts";
}

quint16 MeeTvSettingsHard::port()
{
    return 9982;
}

QString MeeTvSettingsHard::username()
{
    return "hts";
}
