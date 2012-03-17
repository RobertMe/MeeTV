#ifndef MEETVEVENTMODEL_H
#define MEETVEVENTMODEL_H

#include <QObject>

#include "meetvevent.h"
#include "QHtsp/qhtspeventlist.h"
#include "QHtsp/qhtspeventmodel.h"

class MeeTvEventModel : public QHtspEventModel
{
    Q_OBJECT
public:
    MeeTvEventModel();
    explicit MeeTvEventModel(QHtspEventList *events);
    
    Q_INVOKABLE MeeTvEvent *getEventById(int id);
    
};

#endif // MEETVEVENTMODEL_H
