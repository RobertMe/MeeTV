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

#include "meetvchannel.h"

#include "meetvhtsp.h"
#include "meetvservice.h"

MeeTvChannel::MeeTvChannel(QObject *parent) :
    QHtspChannel(MeeTvHtsp::instance(), parent), m_eventModel(0), m_meetvService(0)
{
}

MeeTvChannel::MeeTvChannel(const QHtspChannel& channel, QObject *parent) :
    QHtspChannel(channel, parent), m_eventModel(0), m_meetvService(0)
{
}

MeeTvEventModel *MeeTvChannel::eventsModel()
{
    if(!m_eventModel)
        m_eventModel = new MeeTvEventModel(events(), this);

    return m_eventModel;
}

MeeTvService *MeeTvChannel::service()
{
    if(!QHtspChannel::service() && m_meetvService)
    {
        delete m_meetvService;
        m_meetvService = 0;
    }
    else
    {
        if(m_meetvService && QHtspChannel::service()->name() != m_meetvService->name())
        {
            delete m_meetvService;
            m_meetvService = 0;
        }
        if(QHtspChannel::service() && !m_meetvService)
        {
            m_meetvService = dynamic_cast<MeeTvService*>(QHtspChannel::service());
            if(!m_meetvService)
                m_meetvService = new MeeTvService(*QHtspChannel::service(), this);
        }
    }

    return m_meetvService;
}

void MeeTvChannel::setService(MeeTvService *service)
{
    if(m_meetvService)
        delete m_meetvService;

    m_meetvService = service;
    QHtspChannel::setService(service);
}
