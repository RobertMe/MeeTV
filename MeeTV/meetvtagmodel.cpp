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

#include "meetvtagmodel.h"

MeeTvTagModel::MeeTvTagModel(QHtspTagList *tags, QObject *parent) :
    QHtspTagModel(tags, parent)
{
}

MeeTvTag *MeeTvTagModel::get(int index)
{
    return getTagByIndex(index);
}

MeeTvTag *MeeTvTagModel::getTagById(qint64 id)
{
    return new MeeTvTag(*QHtspTagModel::getTagById(id), this);
}

MeeTvTag *MeeTvTagModel::getTagByIndex(int index)
{
    return new MeeTvTag(*QHtspTagModel::getTagByIndex(index), this);
}

MeeTvModelHelper *MeeTvTagModel::helper(QObject *parent)
{
    MeeTvModelHelper *helper = new MeeTvModelHelper(this, parent);
    helper->sort(1);

    return helper;
}
