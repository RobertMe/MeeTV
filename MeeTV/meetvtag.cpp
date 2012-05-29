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

#include "meetvtag.h"

MeeTvTag::MeeTvTag(QObject *parent) :
    QHtspTag(MeeTvHtsp::instance(), parent), m_channelsModel(0)
{
}

MeeTvTag::MeeTvTag(const QHtspTag &tag, QObject *parent) :
    QHtspTag(tag, parent), m_channelsModel(0)
{
}

MeeTvChannelModel *MeeTvTag::channelsModel()
{
    if(!m_channelsModel)
        m_channelsModel = new MeeTvChannelModel(channels(), this);

    return m_channelsModel;
}
