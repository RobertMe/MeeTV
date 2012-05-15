#include "meetvmodelhelper.h"

MeeTvModelHelper::MeeTvModelHelper(MeeTvModel *model, QObject *parent) :
    QSortFilterProxyModel(parent ? parent : dynamic_cast<QObject*>(model))
{
    setModel(model);

    connect(this, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SIGNAL(itemsChanged()));
    connect(this, SIGNAL(rowsInserted(const QModelIndex&, int, int)), &m_dirtyTimer, SLOT(start()));
    connect(this, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), &m_dirtyTimer, SLOT(start()));
    connect(this, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(_dataChanged(QModelIndex,QModelIndex)));

    m_dirtyTimer.setSingleShot(true);
    connect(&m_dirtyTimer, SIGNAL(timeout()), this, SLOT(_resort()));
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

void MeeTvModelHelper::_dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight)
{
    if(topLeft.column() < sortColumn() && bottomRight.column() > sortColumn())
        return;

    m_dirtyTimer.start();
}

void MeeTvModelHelper::_resort()
{
    QSortFilterProxyModel::sort(sortColumn(), sortOrder());
}
