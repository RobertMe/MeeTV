#include "meetvdvrentrymodel.h"

MeeTvDvrEntryModel::MeeTvDvrEntryModel(QHtspDvrEntryList *dvrEntries) :
    QHtspDvrEntryModel(dvrEntries), m_helper(0)
{
}

MeeTvDvrEntry *MeeTvDvrEntryModel::get(int index)
{
    return getDvrEntryByIndex(index);
}

MeeTvDvrEntry *MeeTvDvrEntryModel::getDvrEntryById(int id)
{
    return new MeeTvDvrEntry(*QHtspDvrEntryModel::getDvrEntryById(id));
}

MeeTvDvrEntry *MeeTvDvrEntryModel::getDvrEntryByIndex(int index)
{
    return new MeeTvDvrEntry(*QHtspDvrEntryModel::getDvrEntryByIndex(index));
}

MeeTvModelHelper *MeeTvDvrEntryModel::helper()
{
    if(!m_helper)
    {
        m_helper = new MeeTvModelHelper(this);
        m_helper->sort(2);
    }

    return m_helper;
}
