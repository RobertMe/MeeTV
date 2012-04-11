#include "meetvmodelhelper.h"

MeeTvModelHelper::MeeTvModelHelper(MeeTvModel *model) :
    QSortFilterProxyModel(dynamic_cast<QObject*>(model))
{
    setModel(model);
    connect(this, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SIGNAL(itemsChanged()));
}

MeeTvModel *MeeTvModelHelper::model()
{
    return m_model;
}

void MeeTvModelHelper::setModel(MeeTvModel *model)
{
    m_model = model;
    QAbstractItemModel *itemModel = dynamic_cast<QAbstractItemModel*>(model);
    if(!itemModel)
        m_model = 0;
    setSourceModel(itemModel);
}

QObject *MeeTvModelHelper::get(int index)
{
    if(!model())
        return 0;

    return model()->get(mapToSource(this->index(index, 0)).row());
}

void MeeTvModelHelper::sort(int column, Qt::SortOrder order)
{
    QSortFilterProxyModel::sort(column, order);
}
