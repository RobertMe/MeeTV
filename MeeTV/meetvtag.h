#ifndef MEETVTAG_H
#define MEETVTAG_H

#include <QObject>

#include "meetvchannelmodel.h"
#include "meetvhtsp.h"
#include "../QHtsp/qhtsptag.h"

class MeeTvTag : public QHtspTag
{
    Q_OBJECT
    Q_PROPERTY(MeeTvChannelModel *channelsModel READ channelsModel)

public:
    explicit MeeTvTag(QObject *parent = 0);
    MeeTvTag(const QHtspTag &tag, QObject *parent = 0);

    MeeTvChannelModel *channelsModel();

private:
    MeeTvChannelModel *m_channelsModel;
};

#endif // MEETVTAG_H
