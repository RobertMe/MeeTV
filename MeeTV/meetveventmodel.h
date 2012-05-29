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

#ifndef MEETVEVENTMODEL_H
#define MEETVEVENTMODEL_H

#include <QObject>

#include "meetvevent.h"
#include "meetvmodel.h"
#include "meetvmodelhelper.h"
#include "../QHtsp/qhtspeventlist.h"
#include "../QHtsp/qhtspeventmodel.h"

class MeeTvEventModel : public QHtspEventModel, public MeeTvModel
{
    Q_OBJECT
public:
    MeeTvEventModel();
    explicit MeeTvEventModel(QHtspEventList *events, QObject *parent = 0);
    
    Q_INVOKABLE MeeTvEvent *get(int index);
    Q_INVOKABLE MeeTvEvent *getEventById(int id);
    Q_INVOKABLE MeeTvEvent *getEventByIndex(int index);
    Q_INVOKABLE MeeTvModelHelper *helper(QObject *parent = 0);
};

#endif // MEETVEVENTMODEL_H
