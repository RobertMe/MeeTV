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

bool MeeTvSettingsHard::hasHostname()
{
    return true;
}

bool MeeTvSettingsHard::hasPassword()
{
    return true;
}

bool MeeTvSettingsHard::hasPort()
{
    return true;
}

bool MeeTvSettingsHard::hasUsername()
{
    return true;
}
