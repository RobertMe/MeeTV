#include "meetvtagmodel.h"

MeeTvTagModel::MeeTvTagModel(QHtspTagList *tags) :
    QHtspTagModel(tags)
{
}

MeeTvTag *MeeTvTagModel::get(int index)
{
    return getTagByIndex(index);
}

MeeTvTag *MeeTvTagModel::getTagById(qint64 id)
{
    return new MeeTvTag(*QHtspTagModel::getTagById(id));
}

MeeTvTag *MeeTvTagModel::getTagByIndex(int index)
{
    return new MeeTvTag(*QHtspTagModel::getTagByIndex(index));
}
