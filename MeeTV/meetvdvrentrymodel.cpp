#include "meetvdvrentrymodel.h"

MeeTvDvrEntryModel::MeeTvDvrEntryModel(QHtspDvrEntryList *dvrEntries, QObject *parent) :
    QHtspDvrEntryModel(dvrEntries, parent)
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

MeeTvModelHelper *MeeTvDvrEntryModel::helper(QObject *parent)
{
    MeeTvModelHelper *helper = new MeeTvModelHelper(this, parent);
    helper->sort(2);

    return helper;
}
