#include "meetveventmodel.h"

MeeTvEventModel::MeeTvEventModel() :
    QHtspEventModel(new QHtspEventList())
{
}

MeeTvEventModel::MeeTvEventModel(QHtspEventList *events, QObject *parent) :
    QHtspEventModel(events, parent)
{
}

MeeTvEvent *MeeTvEventModel::get(int index)
{
    return getEventByIndex(index);
}

MeeTvEvent *MeeTvEventModel::getEventById(int id)
{
    return new MeeTvEvent(*QHtspEventModel::getEventById(id), this);
}

MeeTvEvent *MeeTvEventModel::getEventByIndex(int index)
{
    QHtspEvent *event = QHtspEventModel::getEventByIndex(index);
    if(!event)
        return new MeeTvEvent(this);

    return new MeeTvEvent(*event, this);
}

MeeTvModelHelper *MeeTvEventModel::helper(QObject *parent)
{
    MeeTvModelHelper *helper = new MeeTvModelHelper(this, parent);
    helper->sort(2);

    return helper;
}
