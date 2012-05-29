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

#ifndef MEETVEPGQUERY_H
#define MEETVEPGQUERY_H

#include <QObject>

#include "meetvchannel.h"
#include "meetveventmodel.h"
#include "meetvtag.h"
#include "../QHtsp/qhtspepgquery.h"

class MeeTvEpgQuery : public QHtspEpgQuery
{
    Q_OBJECT
    Q_PROPERTY(MeeTvEventModel *eventsModel READ eventsModel)
    Q_PROPERTY(MeeTvChannel *channel READ channel WRITE setChannel)
    Q_PROPERTY(MeeTvTag *tag READ tag WRITE setTag)
    Q_PROPERTY(QObject *parent READ parent WRITE setParent)

public:
    explicit MeeTvEpgQuery(QObject *parent = 0);
    MeeTvEpgQuery(const QHtspEpgQuery& epgQuery, QObject *parent = 0);

    MeeTvChannel *channel();
    MeeTvEventModel *eventsModel();
    MeeTvTag *tag();

    void setChannel(MeeTvChannel *channel);
    void setTag(MeeTvTag *tag);

private:
    MeeTvChannel *m_channel;
    MeeTvEventModel *m_eventModel;
    MeeTvTag *m_tag;
    
};

#endif // MEETVEPGQUERY_H
