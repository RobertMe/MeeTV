#include "meetvdvrentrymodel.h"

MeeTvDvrEntryModel::MeeTvDvrEntryModel(QHtspDvrEntryList *dvrEntries) :
    QHtspDvrEntryModel(dvrEntries)
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
