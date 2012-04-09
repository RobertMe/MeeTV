#ifndef MEETVSETTINGS_H
#define MEETVSETTINGS_H

#include <QObject>

class MeeTvSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString hostname READ hostname NOTIFY hostnameChanged)
    Q_PROPERTY(quint16 port READ port NOTIFY portChanged)
    Q_PROPERTY(QString username READ username NOTIFY usernameChanged)

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

    Q_INVOKABLE virtual void open() { }

signals:
    void hostnameChanged();
    void passwordChanged();
    void portChanged();
    void usernameChanged();
};

#endif // MEETVSETTINGS_H
