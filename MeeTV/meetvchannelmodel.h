#ifndef MEETVCHANNELMODEL_H
#define MEETVCHANNELMODEL_H

#include <QObject>

#include "meetvchannel.h"
#include "meetvmodel.h"
#include "meetvmodelhelper.h"
#include "../QHtsp/qhtspchannellist.h"
#include "../QHtsp/qhtspchannelmodel.h"

class MeeTvChannelModel : public QHtspChannelModel, public MeeTvModel
{
    Q_OBJECT
public:
    MeeTvChannelModel();
    MeeTvChannelModel(QHtspChannelList *channels, QObject *parent = 0);
    
    Q_INVOKABLE MeeTvChannel *get(int index);
    Q_INVOKABLE MeeTvChannel *getChannelById(int id);
    Q_INVOKABLE MeeTvChannel *getChannelByIndex(int i);
    Q_INVOKABLE MeeTvModelHelper *helper(QObject *parent = 0);

};

#endif // MEETVCHANNELMODEL_H
