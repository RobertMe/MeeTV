#include "meetvtagmodel.h"

MeeTvTagModel::MeeTvTagModel(QHtspTagList *tags) :
    QHtspTagModel(tags), m_helper(0)
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

MeeTvModelHelper *MeeTvTagModel::helper()
{
    if(!m_helper)
        m_helper = new MeeTvModelHelper(this);

    return m_helper;
}
