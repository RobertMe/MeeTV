#ifndef MEETVTAG_H
#define MEETVTAG_H

#include <QObject>

#include "meetvchannelmodel.h"
#include "meetvhtsp.h"
#include "QHtsp/qhtsptag.h"

class MeeTvTag : public QHtspTag
{
    Q_OBJECT
public:
    explicit MeeTvTag(QObject *parent = 0);
    MeeTvTag(const QHtspTag &tag, QObject *parent = 0);
};

#endif // MEETVTAG_H
