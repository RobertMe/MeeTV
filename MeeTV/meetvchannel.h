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

#ifndef MEETVCHANNEL_H
#define MEETVCHANNEL_H

#include <QObject>

#include "meetveventmodel.h"
#include "../QHtsp/qhtspchannel.h"

class MeeTvService;
class MeeTvChannel : public QHtspChannel
{
    Q_OBJECT
    Q_PROPERTY(MeeTvEventModel *eventsModel READ eventsModel)
    Q_PROPERTY(MeeTvService *service READ service WRITE setService NOTIFY serviceChanged)
    Q_PROPERTY(QObject *parent READ parent WRITE setParent)

public:
    explicit MeeTvChannel(QObject *parent = 0);
    MeeTvChannel(const QHtspChannel& channel, QObject *parent = 0);

    MeeTvEventModel *eventsModel();
    MeeTvService *service();

    void setService(MeeTvService *service);

signals:
    void serviceChanged();

private:
    MeeTvEventModel *m_eventModel;
    MeeTvService *m_meetvService;

};

#endif // MEETVCHANNEL_H
