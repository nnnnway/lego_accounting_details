#ifndef NEWNABORFORM_H
#define NEWNABORFORM_H

#include "addnewdetail.h"
#include <QDialog>
#include <QStandardItemModel>

#include "detail.h"

namespace Ui {
class NewNaborForm;
}

class NewNaborForm : public QDialog {
    Q_OBJECT

private:
    Ui::NewNaborForm* ui;
    AddNewDetail* form;
    QList<Detail*>* details;
    QStandardItemModel* model;

public:
    explicit NewNaborForm(QWidget* parent = nullptr);
    ~NewNaborForm();

private:
    void setupModel();
    void addModelItem(Detail* detail);

private slots:
    void on_pushButton_released();
    void on_buttonBox_accepted();
};

#endif // NEWNABORFORM_H
