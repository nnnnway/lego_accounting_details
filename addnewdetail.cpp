#include "addnewdetail.h"
#include "ui_addnewdetail.h"
#include <QFileDialog>
#include <QDebug>


AddNewDetail::AddNewDetail(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AddNewDetail)
{
    ui->setupUi(this);
    detail = nullptr;
    img = nullptr;

    hideAllError();

    QPalette palette = ui->codeErrorLabel->palette();
    palette.setColor(ui->countErrorLabel->foregroundRole(), Qt::red);
    ui->codeErrorLabel->setPalette(palette);
    ui->countErrorLabel->setPalette(palette);
    ui->nameErrorLabel->setPalette(palette);
}

AddNewDetail::~AddNewDetail()
{
    delete ui;
}

void AddNewDetail::hideAllError(){
    ui->codeErrorLabel->hide();
    ui->countErrorLabel->hide();
    ui->nameErrorLabel->hide();
}

Detail* AddNewDetail::getDetail(){
    return detail;
}

void AddNewDetail::setDetail(Detail* x){
    ui->code->setText(QString::number(detail->getCode()));
    ui->count->setText(QString::number(detail->getCount()));
    ui->name->setText(detail->getName());
    this->detail = x;
}

void AddNewDetail::on_select_image_pressed() {
    // Определить класс диалогового окна файла
    QFileDialog *fileDialog = new QFileDialog(this);
    // определить заголовок файла
    fileDialog-> setWindowTitle (tr("Открыть изображение"));
    // Установить путь к файлу по умолчанию
    fileDialog->setDirectory(".");
    // Установить фильтр файлов
    fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)"));
    // Настройка позволяет выбрать несколько файлов, по умолчанию используется только один файл QFileDialog :: ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFile);
    // Установить режим просмотра
    fileDialog->setViewMode(QFileDialog::Detail);
    // выводим путь ко всем выбранным файлам
    QStringList fileNames;
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
    }
    if (fileNames.size() == 0) {
        return;
    }
    img = new QImage(fileNames[0]);
    delete fileDialog;
}

void AddNewDetail::on_save_pressed(){
    QString code = ui->code->toPlainText();
    QString count = ui->count->toPlainText();
    QString name = ui->name->toPlainText();

    hideAllError();

    bool isOk = false;
    bool hasError = false;

    int code_ = code.toInt(&isOk);

    if(!isOk){
        ui->codeErrorLabel->show();
        hasError = true;
    }

    int count_ = count.toInt(&isOk);

    if(!isOk){
        ui->countErrorLabel->show();
        hasError = true;
    }

    if(name.size() < 2){
        ui->nameErrorLabel->show();
        hasError = true;
    }

    if(hasError == true){
        return;
    }


    if (detail == nullptr){
        detail = new Detail();
    }

    detail->setCode(code_);
    detail->setCount(count_);
    detail->setName(name);
    detail->setPicture(img);

    accept();
}

void AddNewDetail::on_close_pressed(){
    close();
}
