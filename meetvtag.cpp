#include "meetvtag.h"

MeeTvTag::MeeTvTag(QObject *parent) :
    QHtspTag(MeeTvHtsp::instance(), parent)
{
}

MeeTvTag::MeeTvTag(const QHtspTag &tag, QObject *parent) :
    QHtspTag(tag, parent)
{
}
