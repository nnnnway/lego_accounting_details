#include "newnaborform.h"
#include "ui_newnaborform.h"

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
    QString invent_Number = ui->lineEdit_3->text();
}
