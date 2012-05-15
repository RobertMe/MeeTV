#include "meetvchannelmodel.h"

MeeTvChannelModel::MeeTvChannelModel() :
    QHtspChannelModel(new QHtspChannelList(this))
{
}

MeeTvChannelModel::MeeTvChannelModel(QHtspChannelList *channels) :
    QHtspChannelModel(channels)
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

MeeTvModelHelper *MeeTvChannelModel::helper(QObject *parent)
{
    MeeTvModelHelper *helper = new MeeTvModelHelper(this, parent);
    helper->sort(2);

    return helper;
}
