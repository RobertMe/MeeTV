#ifndef MEETVDVRENTRYMODEL_H
#define MEETVDVRENTRYMODEL_H

#include <QObject>

#include "meetvdvrentry.h"
#include "meetvmodel.h"
#include "QHtsp/qhtspdvrentrylist.h"
#include "QHtsp/qhtspdvrentrymodel.h"

class MeeTvDvrEntryModel : public QHtspDvrEntryModel, public MeeTvModel
{
    Q_OBJECT
public:
    explicit MeeTvDvrEntryModel(QHtspDvrEntryList *dvrEntries);
    
    Q_INVOKABLE MeeTvDvrEntry *get(int index);
    Q_INVOKABLE MeeTvDvrEntry *getDvrEntryById(int id);
    Q_INVOKABLE MeeTvDvrEntry *getDvrEntryByIndex(int index);
};

#endif // MEETVDVRENTRYMODEL_H
