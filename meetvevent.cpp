#include "meetvevent.h"

MeeTvEvent::MeeTvEvent(QObject *parent) :
    QHtspEvent(MeeTvHtsp::instance(), -1, parent)
{
}
