#include "meetveventmodel.h"

MeeTvEventModel::MeeTvEventModel() :
    QHtspEventModel(new QHtspEventList())
{
}

MeeTvEventModel::MeeTvEventModel(QHtspEventList *events) :
    QHtspEventModel(events)
{
}

MeeTvEvent *MeeTvEventModel::getEventById(int id)
{
    return new MeeTvEvent(*QHtspEventModel::getEventById(id));
}
