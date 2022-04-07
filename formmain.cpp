#include "formmain.h"
#include "ui_formmain.h"
#include "widget.h"
#include <QDebug>

FormMain::FormMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMain)
{
    ui->setupUi(this);
}

FormMain::~FormMain()
{
    delete ui;
}

void FormMain::on_pushButton_clicked()
{

}


void FormMain::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
    {
        Widget::Execute();
    }
}


