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

    virtual bool hasHostname() = 0;
    virtual bool hasPassword() = 0;
    virtual bool hasPort() = 0;
    virtual bool hasUsername() = 0;

    virtual void open() { }
};

#endif // MEETVSETTINGS_H
