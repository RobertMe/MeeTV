#ifndef MEETVDVRENTRYMODEL_H
#define MEETVDVRENTRYMODEL_H

#include <QObject>

#include "meetvdvrentry.h"
#include "QHtsp/qhtspdvrentrylist.h"
#include "QHtsp/qhtspdvrentrymodel.h"

class MeeTvDvrEntryModel : public QHtspDvrEntryModel
{
    Q_OBJECT
public:
    explicit MeeTvDvrEntryModel(QHtspDvrEntryList *dvrEntries);
    
    Q_INVOKABLE MeeTvDvrEntry *getDvrEntryById(int id);
    
};

#endif // MEETVDVRENTRYMODEL_H
