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

#include "meetvchannelmodel.h"

MeeTvChannelModel::MeeTvChannelModel() :
    QHtspChannelModel(new QHtspChannelList(this))
{
}

MeeTvChannelModel::MeeTvChannelModel(QHtspChannelList *channels, QObject *parent) :
    QHtspChannelModel(channels, parent)
{
}

MeeTvChannel *MeeTvChannelModel::get(int index)
{
    return getChannelByIndex(index);
}

MeeTvChannel *MeeTvChannelModel::getChannelById(int id)
{
    return new MeeTvChannel(*QHtspChannelModel::getChannelById(id), this);
}

MeeTvChannel *MeeTvChannelModel::getChannelByIndex(int i)
{
    return new MeeTvChannel(*QHtspChannelModel::getChannelByIndex(i), this);
}

MeeTvModelHelper *MeeTvChannelModel::helper(QObject *parent)
{
    MeeTvModelHelper *helper = new MeeTvModelHelper(this, parent);
    helper->sort(2);

    return helper;
}
