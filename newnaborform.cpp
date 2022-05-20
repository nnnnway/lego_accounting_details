#include "newnaborform.h"
#include "ui_newnaborform.h"

#include <QDebug>
#include <QStandardItem>
#include <QPixmap>


#include "databasemanager.h"

NewNaborForm::NewNaborForm(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::NewNaborForm)
{
    ui->setupUi(this);
    details = nullptr;

    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    setupModel();
}

NewNaborForm::~NewNaborForm()
{
    delete ui;
}

void NewNaborForm::setupModel(){
    model->setColumnCount(4);
    model->setHeaderData(0, Qt::Horizontal, "Код");
    model->setHeaderData(1, Qt::Horizontal, "Картинка");
    model->setHeaderData(2, Qt::Horizontal, "Имя");
    model->setHeaderData(3, Qt::Horizontal, "Количество");
}

void NewNaborForm::on_pushButton_released()
{
    form = new AddNewDetail(this);
    switch(form->exec()) {
        case QDialog::Accepted: {
            Detail * detail = form->getDetail();
            if (details == nullptr){
                details = new QList<Detail*>();
            }
            details->append(detail);
            addModelItem(detail);
        }
        case QDialog::Rejected: {
            delete form;
            form = nullptr;
        }
    }
}

void NewNaborForm::setNabor(Nabor* nabor) {
    ui->nameLine->setText(nabor->getNameNabor());
    ui->invent_Number_Line->setText(nabor->getInvetn_Number());
    ui->priceLine->setText(QString::number(nabor->getPrice()));
    this->nabor = nabor;
}

void NewNaborForm::addModelItem(Detail* detail){
    QList<QStandardItem*> items;

    QStandardItem *itemCode = new QStandardItem(QString::number(detail->getCode()));
    QStandardItem *itemPicture = new QStandardItem();
    if (detail->getPicture() != nullptr) {
        itemPicture->setData(QVariant(QPixmap::fromImage(*detail->getPicture())), Qt::DecorationRole);
    }
    QStandardItem *itemName = new QStandardItem(detail->getName());
    QStandardItem *itemCount = new QStandardItem(QString::number(detail->getCount()));

    items.append(itemCode);
    items.append(itemPicture);
    items.append(itemName);
    items.append(itemCount);

    model->insertRow(0, items);
}

void NewNaborForm::on_buttonBox_accepted(){
    QString name = ui->nameLine->text();
    QString price = ui->priceLine->text();
    QString invetn_Number = ui->invent_Number_Line->text();

    bool isOk = false;
    bool hasError = false;

    float priceLine = price.toFloat(&isOk);

    if(!isOk){
        ui->priceLine->show();
        hasError = true;
    }

    if(name.size() < 1){
        ui->invent_Number_Line->show();
        hasError = true;
    }

    if(invetn_Number.size() < 1){
        hasError = true;
    }

    if(hasError == true){
        return;
    }

    DataBaseManager* db = DataBaseManager::getInstanse();

    if(nabor == nullptr) {
        Nabor nabor;
        nabor.setNameNabor(name);
        nabor.setPrice(priceLine);
        nabor.setInvetn_Number(invetn_Number);
        nabor.setDetails(details);
        db->insertNabor(&nabor);
    } else {
        nabor->setNameNabor(name);
        nabor->setInvetn_Number(invetn_Number);
        nabor->setPrice(priceLine);

        db->updateNabor(nabor);
    }
}











