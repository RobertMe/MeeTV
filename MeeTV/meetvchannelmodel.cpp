#include "meetvchannelmodel.h"

MeeTvChannelModel::MeeTvChannelModel() :
    QHtspChannelModel(new QHtspChannelList(this))
{
}

MeeTvChannelModel::MeeTvChannelModel(QHtspChannelList *channels, QObject *parent) :
    QHtspChannelModel(channels, parent)
{
}

MeeTvChannel *MeeTvChannelModel::get(int index)
{
    return getChannelByIndex(index);
}

MeeTvChannel *MeeTvChannelModel::getChannelById(int id)
{
    return new MeeTvChannel(*QHtspChannelModel::getChannelById(id), this);
}

MeeTvChannel *MeeTvChannelModel::getChannelByIndex(int i)
{
    return new MeeTvChannel(*QHtspChannelModel::getChannelByIndex(i), this);
}

MeeTvModelHelper *MeeTvChannelModel::helper(QObject *parent)
{
    MeeTvModelHelper *helper = new MeeTvModelHelper(this, parent);
    helper->sort(2);

    return helper;
}
