#ifndef MEETVMODEL_H
#define MEETVMODEL_H

#include <QObject>

class MeeTvModel
{
public:
    MeeTvModel() { }

    Q_INVOKABLE virtual QObject* get(int index) = 0;
};

#endif // MEETVMODEL_H
