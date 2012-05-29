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

#ifndef MEETVTAGMODEL_H
#define MEETVTAGMODEL_H

#include <QObject>

#include "meetvtag.h"
#include "meetvmodel.h"
#include "../QHtsp/qhtsptaglist.h"
#include "../QHtsp/qhtsptagmodel.h"

class MeeTvTagModel : public QHtspTagModel, public MeeTvModel
{
    Q_OBJECT

public:
    explicit MeeTvTagModel(QHtspTagList *tags, QObject *parent = 0);
    
    Q_INVOKABLE MeeTvTag *get(int index);
    Q_INVOKABLE MeeTvTag *getTagById(qint64 id);
    Q_INVOKABLE MeeTvTag *getTagByIndex(int index);
    Q_INVOKABLE MeeTvModelHelper *helper(QObject *parent = 0);
    
};

#endif // MEETVTAGMODEL_H
