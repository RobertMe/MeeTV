#ifndef MEETVMODELHELPER_H
#define MEETVMODELHELPER_H

#include <QSortFilterProxyModel>
#include <QTimer>

#include "meetvmodel.h"

class MeeTvModelHelper : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(MeeTvModel *model READ model WRITE setModel)
    Q_PROPERTY(int count READ rowCount NOTIFY countChanged)

public:
    explicit MeeTvModelHelper(MeeTvModel *model = 0);
    
    MeeTvModel *model();

    void setModel(MeeTvModel *model);

    Q_INVOKABLE QObject *get(int index);
    Q_INVOKABLE void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

signals:
    void countChanged();
    void itemsChanged();

private:
    QTimer m_dirtyTimer;
    MeeTvModel *m_model;

private slots:
    void _dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
    void _resort();
};

#endif // MEETVMODELHELPER_H
