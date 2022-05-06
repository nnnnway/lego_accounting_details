#include "newnaborform.h"
#include "ui_newnaborform.h"
#include "nabor.h"
#include "databasemanager.h"

NewNaborForm::NewNaborForm(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::NewNaborForm)
{
    ui->setupUi(this);
}

NewNaborForm::~NewNaborForm()
{
    delete ui;
}

void NewNaborForm::on_pushButton_released()
{
    form = new AddNewDetail();
    form->show();
}

void NewNaborForm::on_lineEdit_accepted(){
    QString name = ui->lineEdit->text();
    QString price = ui->lineEdit_2->text();
    QString invetn_Number = ui->lineEdit_3->text();

    Nabor nabor;
    nabor.setNameNabor(name);
    nabor.setPrice(price.toFloat());
    nabor.setInvetn_Number(invetn_Number);

    DataBaseManager* db = DataBaseManager::getInstanse();
    db->insertNabor(&nabor);
}
