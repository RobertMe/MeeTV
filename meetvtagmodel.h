#ifndef MEETVTAGMODEL_H
#define MEETVTAGMODEL_H

#include <QObject>

#include "meetvtag.h"
#include "QHtsp/qhtsptaglist.h"
#include "QHtsp/qhtsptagmodel.h"

class MeeTvTagModel : public QHtspTagModel
{
    Q_OBJECT

public:
    explicit MeeTvTagModel(QHtspTagList *tags);
    
    Q_INVOKABLE MeeTvTag *getTagById(qint64 id);
    
};

#endif // MEETVTAGMODEL_H
