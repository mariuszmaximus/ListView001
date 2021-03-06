#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringListModel>
#include <qevent.h> // QKeyEvent
#include <qitemselectionmodel.h>
#include <QDebug>  // dziwne Qt6 nie wymaga a Qt5 juz tak

#include "onefile.h"
#include "filesmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    static void Execute();
private:
    Ui::Widget *ui;
    std::vector <OneFile> files;
    inline static int idx_wybrany=0;
#ifdef OLD_VERSION
    QStringListModel *model;
#else
    FilesModel *model;
#endif

    void keyPressEvent(QKeyEvent *event);

public slots:
    void onSelectionChanged(QItemSelection item);
    void onActivated(const QModelIndex &index);
};
#endif // WIDGET_H
