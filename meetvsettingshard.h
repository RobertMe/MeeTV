#ifndef MEETVSETTINGSHARD_H
#define MEETVSETTINGSHARD_H

#include <QObject>
#include <QString>

#include "meetvsettings.h"

class MeeTvSettingsHard : public MeeTvSettings
{
    Q_OBJECT
public:
    explicit MeeTvSettingsHard(QObject *parent = 0);

    QString hostname();
    QString password();
    quint16 port();
    QString username();
};

#endif // MEETVSETTINGSHARD_H
