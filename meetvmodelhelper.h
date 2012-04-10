#ifndef MEETVMODELHELPER_H
#define MEETVMODELHELPER_H

#include <QSortFilterProxyModel>

#include "meetvmodel.h"

class MeeTvModelHelper : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(MeeTvModel *model READ model WRITE setModel)

public:
    explicit MeeTvModelHelper(MeeTvModel *model = 0);
    
    MeeTvModel *model();

    void setModel(MeeTvModel *model);

    Q_INVOKABLE QObject *get(int index);
    Q_INVOKABLE void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

private:
    MeeTvModel *m_model;
};

#endif // MEETVMODELHELPER_H
