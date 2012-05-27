#include "meetvtagmodel.h"

MeeTvTagModel::MeeTvTagModel(QHtspTagList *tags, QObject *parent) :
    QHtspTagModel(tags, parent)
{
}

MeeTvTag *MeeTvTagModel::get(int index)
{
    return getTagByIndex(index);
}

MeeTvTag *MeeTvTagModel::getTagById(qint64 id)
{
    return new MeeTvTag(*QHtspTagModel::getTagById(id), this);
}

MeeTvTag *MeeTvTagModel::getTagByIndex(int index)
{
    return new MeeTvTag(*QHtspTagModel::getTagByIndex(index), this);
}

MeeTvModelHelper *MeeTvTagModel::helper(QObject *parent)
{
    MeeTvModelHelper *helper = new MeeTvModelHelper(this, parent);
    helper->sort(1);

    return helper;
}
