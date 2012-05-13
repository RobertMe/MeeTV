#ifndef MEETVSERVICE_H
#define MEETVSERVICE_H

#include <QObject>

#include "../QHtsp/qhtspservice.h"

class MeeTvService : public QHtspService
{
    Q_OBJECT
public:
    explicit MeeTvService(QHtspChannel *channel, QObject *parent = 0);
    MeeTvService(QHtspMessage &message, QHtspChannel *channel, QObject *parent = 0);
    MeeTvService(const QHtspService &service, QObject *parent = 0);
    
};

#endif // MEETVSERVICE_H
