#include "meetvchannelmodel.h"

MeeTvChannelModel::MeeTvChannelModel() :
    QHtspChannelModel(new QHtspChannelList(this)), m_helper(0)
{
}

MeeTvChannelModel::MeeTvChannelModel(QHtspChannelList *channels) :
    QHtspChannelModel(channels), m_helper(0)
{
}

MeeTvChannel *MeeTvChannelModel::get(int index)
{
    return getChannelByIndex(index);
}

MeeTvChannel *MeeTvChannelModel::getChannelById(int id)
{
    return new MeeTvChannel(*QHtspChannelModel::getChannelById(id));
}

MeeTvChannel *MeeTvChannelModel::getChannelByIndex(int i)
{
    return new MeeTvChannel(*QHtspChannelModel::getChannelByIndex(i));
}

MeeTvModelHelper *MeeTvChannelModel::helper()
{
    if(!m_helper)
    {
        m_helper = new MeeTvModelHelper(this);
        m_helper->sort(2);
    }

    return m_helper;
}
