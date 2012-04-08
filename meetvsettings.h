#ifndef MEETVSETTINGS_H
#define MEETVSETTINGS_H

#include <QObject>

class MeeTvSettings : public QObject
{
    Q_OBJECT
public:
    explicit MeeTvSettings(QObject *parent = 0);
    
    virtual QString hostname() = 0;
    virtual QString password() = 0;
    virtual quint16 port() = 0;
    virtual QString username() = 0;
};

#endif // MEETVSETTINGS_H
