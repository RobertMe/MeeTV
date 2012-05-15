#ifndef MEETVEVENTMODEL_H
#define MEETVEVENTMODEL_H

#include <QObject>

#include "meetvevent.h"
#include "meetvmodel.h"
#include "meetvmodelhelper.h"
#include "../QHtsp/qhtspeventlist.h"
#include "../QHtsp/qhtspeventmodel.h"

class MeeTvEventModel : public QHtspEventModel, public MeeTvModel
{
    Q_OBJECT
public:
    MeeTvEventModel();
    explicit MeeTvEventModel(QHtspEventList *events, QObject *parent = 0);
    
    Q_INVOKABLE MeeTvEvent *get(int index);
    Q_INVOKABLE MeeTvEvent *getEventById(int id);
    Q_INVOKABLE MeeTvEvent *getEventByIndex(int index);
    Q_INVOKABLE MeeTvModelHelper *helper(QObject *parent = 0);
};

#endif // MEETVEVENTMODEL_H
