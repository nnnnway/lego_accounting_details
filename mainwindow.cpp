#include "mainwindow.h"
#include "databasemanager.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTableView>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->editNabor->setEnabled(false);
    ui->deleteNabor->setEnabled(false);
    factory = DataBaseManager::getInstanse()->getNabor();

    warThunder = new QStandardItemModel(this);
    ui->tableView->setModel(warThunder);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSortingEnabled(true);
    setupModel();

    for (Nabor* nabor : *factory) {
        addModelItem(nabor);
    }

    connect(ui->action, SIGNAL(triggered()), this, SLOT(onNewFormTap()));
    connect(ui->tableView,
        SIGNAL(doubleClicked(QModelIndex)),
        this,
        SLOT(doubleClicked(QModelIndex)));

    connect(ui->tableView,
        SIGNAL(clicked(QModelIndex)),
        this,
        SLOT(clicked(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewFormTap()
{
    form = new NewNaborForm(this);
    form->show();
}

void MainWindow::setupModel()
{
    warThunder->setColumnCount(4);
    warThunder->setHeaderData(0, Qt::Horizontal, "Код");
    warThunder->setHeaderData(1, Qt::Horizontal, "Имя");
    warThunder->setHeaderData(2, Qt::Horizontal, "Номер");
    warThunder->setHeaderData(3, Qt::Horizontal, "Цена");
}

void MainWindow::addModelItem(Nabor* nabor)
{
    QList<QStandardItem*> items;

    QStandardItem* itemCode = new QStandardItem(QString::number(nabor->getId()));
    QStandardItem* itemName = new QStandardItem(nabor->getNameNabor());
    QStandardItem* itemInvetnNumber = new QStandardItem(nabor->getInvetn_Number());
    QStandardItem* itemPrice = new QStandardItem(QString::number(nabor->getPrice()));

    items.append(itemCode);
    items.append(itemName);
    items.append(itemInvetnNumber);
    items.append(itemPrice);

    warThunder->insertRow(0, items);
}

void MainWindow::doubleClicked(QModelIndex index)
{
    int row = index.row();
    int idNabor = index.sibling(row, 0).data().toInt();
    qDebug() << idNabor;
}

void MainWindow::clicked(QModelIndex index)
{
    ui->editNabor->setEnabled(true);
    ui->deleteNabor->setEnabled(true);

    int row = index.row();
    int idNabor = index.sibling(row, 0).data().toInt();
    idNaborSelect = idNabor;
    this->index = index;
}

void MainWindow::on_editNabor_pressed(){
    Nabor* delNabor = nullptr;

    for(Nabor* n: *factory){
        if(n->getId() == idNaborSelect) {
            delNabor = n;
        }
    }

    if (delNabor != nullptr){
        form = new NewNaborForm();
        form->setNabor(delNabor);
        form->show();
    }
}

void MainWindow::on_deleteNabor_pressed(){
    Nabor* delNabor = nullptr;

    for(Nabor* n: *factory){
        if(n->getId() == idNaborSelect) {
            delNabor = n;
        }
    }

    if (delNabor != nullptr){
        DataBaseManager::getInstanse()->deleteNabor(delNabor);
    }
    warThunder->removeRow(index.row());
}












