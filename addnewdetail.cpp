#include "addnewdetail.h"
#include "ui_addnewdetail.h"

AddNewDetail::AddNewDetail(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AddNewDetail)
{
    ui->setupUi(this);
}

AddNewDetail::~AddNewDetail()
{
    delete ui;
}
