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

#include "meetvmodelhelper.h"

MeeTvModelHelper::MeeTvModelHelper(MeeTvModel *model, QObject *parent) :
    QSortFilterProxyModel(parent ? parent : dynamic_cast<QObject*>(model))
{
    setModel(model);

    connect(this, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SIGNAL(itemsChanged()));
    connect(this, SIGNAL(rowsInserted(const QModelIndex&, int, int)), &m_dirtyTimer, SLOT(start()));
    connect(this, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), &m_dirtyTimer, SLOT(start()));
    connect(this, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(_dataChanged(QModelIndex,QModelIndex)));

    m_dirtyTimer.setSingleShot(true);
    connect(&m_dirtyTimer, SIGNAL(timeout()), this, SLOT(_resort()));
}

MeeTvModel *MeeTvModelHelper::model()
{
    return m_model;
}

void MeeTvModelHelper::setModel(MeeTvModel *model)
{
    m_model = model;
    QAbstractItemModel *itemModel = dynamic_cast<QAbstractItemModel*>(model);
    if(!itemModel)
        m_model = 0;
    setSourceModel(itemModel);
}

QObject *MeeTvModelHelper::get(int index)
{
    if(!model())
        return 0;

    return model()->get(mapToSource(this->index(index, 0)).row());
}

void MeeTvModelHelper::sort(int column, Qt::SortOrder order)
{
    QSortFilterProxyModel::sort(column, order);
}

void MeeTvModelHelper::_dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    if(topLeft.column() < sortColumn() && bottomRight.column() > sortColumn())
        return;

    m_dirtyTimer.start();
}

void MeeTvModelHelper::_resort()
{
    QSortFilterProxyModel::sort(sortColumn(), sortOrder());
}
