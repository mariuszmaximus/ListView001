#include "filesmodel.h"

int FilesModel::rowCount(const QModelIndex &parent) const
{
    return m_files.size();
}

int FilesModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant FilesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
            return m_files[index.row()].nameOnScreen;
        if (index.column() == 1)
            return m_files[index.row()].filename;
    }
    return QVariant();
}
