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

#ifndef MEETVSETTINGS_H
#define MEETVSETTINGS_H

#include <QObject>

class MeeTvSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString hostname READ hostname NOTIFY hostnameChanged)
    Q_PROPERTY(quint16 port READ port NOTIFY portChanged)
    Q_PROPERTY(QString username READ username NOTIFY usernameChanged)

public:
    explicit MeeTvSettings(QObject *parent = 0);
    
    virtual QString hostname() = 0;
    virtual QString password() = 0;
    virtual quint16 port() = 0;
    virtual QString username() = 0;

    virtual bool hasHostname() = 0;
    virtual bool hasPassword() = 0;
    virtual bool hasPort() = 0;
    virtual bool hasUsername() = 0;

    Q_INVOKABLE virtual void open() { }

signals:
    void hostnameChanged();
    void passwordChanged();
    void portChanged();
    void usernameChanged();
};

#endif // MEETVSETTINGS_H
