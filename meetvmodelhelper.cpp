#include "meetvmodelhelper.h"

MeeTvModelHelper::MeeTvModelHelper(MeeTvModel *model) :
    QSortFilterProxyModel(dynamic_cast<QObject*>(model))
{
    setModel(model);
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

    return model()->get(mapToSource(createIndex(index, 0)).row());
}

void MeeTvModelHelper::sort(int column, Qt::SortOrder order)
{
    QSortFilterProxyModel::sort(column, order);
}
