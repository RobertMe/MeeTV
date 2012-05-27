#ifndef MEETVTAGMODEL_H
#define MEETVTAGMODEL_H

#include <QObject>

#include "meetvtag.h"
#include "meetvmodel.h"
#include "../QHtsp/qhtsptaglist.h"
#include "../QHtsp/qhtsptagmodel.h"

class MeeTvTagModel : public QHtspTagModel, public MeeTvModel
{
    Q_OBJECT

public:
    explicit MeeTvTagModel(QHtspTagList *tags, QObject *parent = 0);
    
    Q_INVOKABLE MeeTvTag *get(int index);
    Q_INVOKABLE MeeTvTag *getTagById(qint64 id);
    Q_INVOKABLE MeeTvTag *getTagByIndex(int index);
    Q_INVOKABLE MeeTvModelHelper *helper(QObject *parent = 0);
    
};

#endif // MEETVTAGMODEL_H
