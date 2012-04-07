#include "meetveventmodel.h"

MeeTvEventModel::MeeTvEventModel() :
    QHtspEventModel(new QHtspEventList())
{
    connect(this, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SIGNAL(itemsChanged()));
}

MeeTvEventModel::MeeTvEventModel(QHtspEventList *events) :
    QHtspEventModel(events)
{
    connect(this, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SIGNAL(itemsChanged()));
}

MeeTvEvent *MeeTvEventModel::get(int index)
{
    return getEventByIndex(index);
}

MeeTvEvent *MeeTvEventModel::getEventById(int id)
{
    return new MeeTvEvent(*QHtspEventModel::getEventById(id));
}

MeeTvEvent *MeeTvEventModel::getEventByIndex(int index)
{
    QHtspEvent *event = QHtspEventModel::getEventByIndex(index);
    if(!event)
        return new MeeTvEvent();

    return new MeeTvEvent(*event);
}
