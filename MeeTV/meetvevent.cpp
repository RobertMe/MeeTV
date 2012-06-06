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

#include "meetvevent.h"

#include <QRegExp>

MeeTvEvent::MeeTvEvent(QObject *parent) :
    QHtspEvent(MeeTvHtsp::instance(), -1, parent), m_nextEvent(0)
{
    connect(this, SIGNAL(descriptionChanged()), this, SIGNAL(htmlDescriptionChanged()));
    connect(this, SIGNAL(longDescriptionChanged()), this, SIGNAL(htmlDescriptionChanged()));
}

MeeTvEvent::MeeTvEvent(const QHtspEvent& event, QObject *parent) :
    QHtspEvent(event, parent), m_nextEvent(0)
{
    connect(this, SIGNAL(descriptionChanged()), this, SIGNAL(htmlDescriptionChanged()));
    connect(this, SIGNAL(longDescriptionChanged()), this, SIGNAL(htmlDescriptionChanged()));
}

QString MeeTvEvent::htmlDescription()
{
    QString text = QString(description());
    if(!longDescription().isEmpty())
        text +=  "<br/><br/>" + longDescription();
    text.replace("\n", "<br/>");
    text.replace(QRegExp("((?:\\S+\\.[a-z]{2,6}/\\S+[a-z/])|(?:www\\.\\S+\\.[a-z]{2,6}))", Qt::CaseInsensitive), "<a href=\"http://\\1\">\\1</a>");
    return text;
}

MeeTvEvent *MeeTvEvent::nextEvent()
{
    if(!m_nextEvent)
    {
        QHtspEvent *next = QHtspEvent::nextEvent();
        if(next)
            m_nextEvent = new MeeTvEvent(*next, this);

    }

    return m_nextEvent;
}

QString MeeTvEvent::startDate()
{
    return start().date().toString();
}
