#include "meetveventmodel.h"

MeeTvEventModel::MeeTvEventModel() :
    QHtspEventModel(new QHtspEventList()), m_helper(0)
{
}

MeeTvEventModel::MeeTvEventModel(QHtspEventList *events) :
    QHtspEventModel(events), m_helper(0)
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

MeeTvModelHelper *MeeTvEventModel::helper()
{
    if(!m_helper)
        m_helper = new MeeTvModelHelper(this);

    return m_helper;
}
