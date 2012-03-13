#ifndef MEETVCHANNEL_H
#define MEETVCHANNEL_H

#include <QObject>

#include "QHtsp/qhtspchannel.h"

class MeeTvChannel : public QHtspChannel
{
    Q_OBJECT
public:
    explicit MeeTvChannel(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // MEETVCHANNEL_H
