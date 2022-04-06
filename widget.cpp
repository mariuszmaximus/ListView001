#include "widget.h"
#include "./ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    files.push_back( OneFile("opis1","plik1.txt")  );
    files.push_back( OneFile("opis2","plik2.txt")  );
    files.push_back( OneFile("opis3","plik3.txt")  );


    // Create model
    model = new QStringListModel(this);

    // Make data
    QStringList List;

    // Using a for loop with index
     for (std::size_t i = 0; i < files.size(); ++i)
     {
         //List.append(cfg->probes[i].c_str());
         List.append(files[i].nameOnScreen);
     }

     // Populate our model
     model->setStringList(List);

     // Glue model and view together
     ui->listView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Return)
    {
        QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();
//        QStringList slist;
//        foreach(const QModelIndex &index, list){
//            slist.append( index.data(Qt::DisplayRole ).toString());
//            qDebug()<< index.row();
//        }
//        qDebug() << slist.join(",");

        if(list.count()==1)
        {
            qDebug() << "Wybrano plik:" << files[list.at(0).row() ].filename;

            QMessageBox msgBox;
            msgBox.setText(files[list.at(0).row() ].filename);
            msgBox.exec();
        }

    }

}
