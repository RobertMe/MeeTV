#include "meetvdvrentrymodel.h"

MeeTvDvrEntryModel::MeeTvDvrEntryModel(QHtspDvrEntryList *dvrEntries) :
    QHtspDvrEntryModel(dvrEntries)
{
}

MeeTvDvrEntry *MeeTvDvrEntryModel::getDvrEntryById(int id)
{
    return new MeeTvDvrEntry(*QHtspDvrEntryModel::getDvrEntryById(id));
}
