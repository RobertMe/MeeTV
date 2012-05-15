#include "meetvtag.h"

MeeTvTag::MeeTvTag(QObject *parent) :
    QHtspTag(MeeTvHtsp::instance(), parent), m_channelsModel(0)
{
}

MeeTvTag::MeeTvTag(const QHtspTag &tag, QObject *parent) :
    QHtspTag(tag, parent), m_channelsModel(0)
{
}

MeeTvChannelModel *MeeTvTag::channelsModel()
{
    if(!m_channelsModel)
        m_channelsModel = new MeeTvChannelModel(channels(), this);

    return m_channelsModel;
}
