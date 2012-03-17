#include "meetvchannelmodel.h"

MeeTvChannelModel::MeeTvChannelModel() :
    QHtspChannelModel(new QHtspChannelList(this))
{
}

MeeTvChannelModel::MeeTvChannelModel(QHtspChannelList *channels) :
    QHtspChannelModel(channels)
{
}

MeeTvChannel *MeeTvChannelModel::getChannelById(int id)
{
    return new MeeTvChannel(*QHtspChannelModel::getChannelById(id));
}

MeeTvChannel *MeeTvChannelModel::getChannelByIndex(int i)
{
    return new MeeTvChannel(*QHtspChannelModel::getChannelByIndex(i));
}
