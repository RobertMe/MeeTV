#include "meetvtag.h"

MeeTvTag::MeeTvTag(QObject *parent) :
    QHtspTag(MeeTvHtsp::instance(), parent)
{
}
