#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringListModel>
#include <qevent.h> // QKeyEvent

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


//
struct OneFile{
    QString nameOnScreen;
    QString filename;
    OneFile(QString _nameOnScreen, QString _filename )
    {
        nameOnScreen = _nameOnScreen;
        filename = _filename;
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    std::vector <OneFile> files;
    QStringListModel *model;
protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // WIDGET_H
