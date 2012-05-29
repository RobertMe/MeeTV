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

#ifndef MEETVMODELHELPER_H
#define MEETVMODELHELPER_H

#include <QSortFilterProxyModel>
#include <QTimer>

#include "meetvmodel.h"

class MeeTvModelHelper : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(MeeTvModel *model READ model WRITE setModel)
    Q_PROPERTY(int count READ rowCount NOTIFY countChanged)

public:
    explicit MeeTvModelHelper(MeeTvModel *model = 0, QObject *parent = 0);
    
    MeeTvModel *model();

    void setModel(MeeTvModel *model);

    Q_INVOKABLE QObject *get(int index);
    Q_INVOKABLE void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void countChanged();
    void itemsChanged();

private:
    QTimer m_dirtyTimer;
    MeeTvModel *m_model;

private slots:
    void _dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void _resort();
};

#endif // MEETVMODELHELPER_H
