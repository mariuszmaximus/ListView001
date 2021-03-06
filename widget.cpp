#include "widget.h"
#include "./ui_widget.h"

#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose); // free on close !!!


    for (int i=1;i<55;++i)
    {
        QString sOpis = QString("Item%1").arg(i);
        QString sPlik = QString("plik%1.txt").arg(i);
        files.push_back(OneFile(sOpis,sPlik));
    }

#ifdef OLD_VERSION
    // Create model
    model = new QStringListModel(this);

    // Make data
    QStringList List;

    // Using a for loop with index
    for (std::size_t i = 0; i < files.size(); ++i)
    {
        // List.append(cfg->probes[i].c_str());
        List.append(files[i].nameOnScreen);
    }

    // Populate our model
    model->setStringList(List);

    // Glue model and view together
    ui->listView->setModel(model);
#else
    model = new FilesModel(files);
    // Glue model and view together
    ui->listView->setModel(model);

    ui->tableView->setModel(model);
#endif

    // Connect the combobox's signal to our own
    connect(ui->listView, SIGNAL(activated(QModelIndex)),
            this, SLOT(onActivated(QModelIndex)));

    connect(ui->listView, SIGNAL(clicked(QModelIndex)),
            this, SLOT(onActivated(QModelIndex)));

    connect(ui->listView->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
            this, SLOT(onSelectionChanged(QItemSelection)));

    // select item on list
    QItemSelectionModel::SelectionFlags flag = QItemSelectionModel::Select;
    ui->listView->selectionModel()->select(model->index(idx_wybrany), flag); //

    // edit mode OFF
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Widget::~Widget()
{
    qDebug() << "!!! DESTRUCTOR !!!";
    delete model;
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
    {
        QModelIndexList list = ui->listView->selectionModel()->selectedIndexes();

        if (list.count() == 1)
        {
            qDebug() << "Wybrano plik:" << files[list.at(0).row()].filename;

            //            QMessageBox msgBox;
            //            msgBox.setText(files[list.at(0).row() ].filename);
            //            msgBox.exec();
            idx_wybrany = list.at(0).row();
        }
    }
}

void Widget::onActivated(const QModelIndex &index)
{

    qDebug() << "onActivated  index.row()=" << index.row();

    close();
}

void Widget::onSelectionChanged(QItemSelection item)
{
    qDebug() << "onSelectionChanged item.count()=" << item.count();
}


void Widget::Execute()
{
  Widget * dlg = new Widget(nullptr);
  dlg->show();
}
