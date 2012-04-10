#include "meetveventmodel.h"

MeeTvEventModel::MeeTvEventModel() :
    QHtspEventModel(new QHtspEventList()), m_helper(0)
{
    connect(this, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SIGNAL(itemsChanged()));
}

MeeTvEventModel::MeeTvEventModel(QHtspEventList *events) :
    QHtspEventModel(events), m_helper(0)
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

MeeTvModelHelper *MeeTvEventModel::helper()
{
    if(!m_helper)
        m_helper = new MeeTvModelHelper(this);

    return m_helper;
}
