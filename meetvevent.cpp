#include "meetvevent.h"

MeeTvEvent::MeeTvEvent(QObject *parent) :
    QHtspEvent(MeeTvHtsp::instance(), -1, parent)
{
}

MeeTvEvent::MeeTvEvent(const QHtspEvent& event, QObject *parent) :
    QHtspEvent(event, parent)
{
}
