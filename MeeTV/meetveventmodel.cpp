#include "meetveventmodel.h"

MeeTvEventModel::MeeTvEventModel() :
    QHtspEventModel(new QHtspEventList())
{
}

MeeTvEventModel::MeeTvEventModel(QHtspEventList *events) :
    QHtspEventModel(events)
{
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

MeeTvModelHelper *MeeTvEventModel::helper(QObject *parent)
{
    MeeTvModelHelper *helper = new MeeTvModelHelper(this, parent);
    helper->sort(2);

    return helper;
}
