#ifndef FILESMODEL_H
#define FILESMODEL_H

#include <QAbstractListModel>
#include "onefile.h"

class FilesModel : public QAbstractListModel
{
    Q_OBJECT
private:
    std::vector<OneFile> m_files;

public:
    // (QT CREATOR) explicit FilesModel(QObject *parent = nullptr);
    FilesModel(std::vector<OneFile> files)
    {
        m_files = files;
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // FILESMODEL_H
