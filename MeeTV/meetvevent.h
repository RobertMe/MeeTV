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

#ifndef MEETVEVENT_H
#define MEETVEVENT_H

#include <QObject>

#include "meetvhtsp.h"
#include "../QHtsp/qhtspevent.h"

class MeeTvEvent : public QHtspEvent
{
    Q_OBJECT
    Q_PROPERTY(QString htmlDescription READ htmlDescription NOTIFY htmlDescriptionChanged())
    Q_PROPERTY(MeeTvEvent *nextEvent READ nextEvent NOTIFY nextEventChanged())
    Q_PROPERTY(MeeTvEvent *previousEvent READ previousEvent NOTIFY previousEventChanged)
    Q_PROPERTY(QString startDate READ startDate)
    Q_PROPERTY(QObject *parent READ parent WRITE setParent)

public:
    explicit MeeTvEvent(QObject *parent = 0);
    MeeTvEvent(const QHtspEvent& event, QObject *parent = 0);
    
    QString htmlDescription();
    MeeTvEvent *nextEvent();
    MeeTvEvent *previousEvent();
    QString startDate();

signals:
    void htmlDescriptionChanged();
    void nextEventChanged();
    void previousEventChanged();

private:
    MeeTvEvent *m_nextEvent;
    MeeTvEvent *m_previousEvent;

private slots:
    void _resetPreviousEvent();
    
};

#endif // MEETVEVENT_H
