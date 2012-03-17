#ifndef MEETVCHANNELMODEL_H
#define MEETVCHANNELMODEL_H

#include <QObject>

#include "meetvchannel.h"
#include "QHtsp/qhtspchannellist.h"
#include "QHtsp/qhtspchannelmodel.h"

class MeeTvChannelModel : public QHtspChannelModel
{
    Q_OBJECT
public:
    MeeTvChannelModel();
    MeeTvChannelModel(QHtspChannelList *channels);
    
    Q_INVOKABLE MeeTvChannel *getChannelById(int id);
    Q_INVOKABLE MeeTvChannel *getChannelByIndex(int i);

};

#endif // MEETVCHANNELMODEL_H
