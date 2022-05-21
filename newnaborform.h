#ifndef NEWNABORFORM_H
#define NEWNABORFORM_H

#include "addnewdetail.h"
#include <QDialog>
#include <QStandardItemModel>

#include "detail.h"
#include "nabor.h"

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
    Nabor* nabor;
    int idDetailsSelect;
    QModelIndex indx;

public:
    explicit NewNaborForm(QWidget* parent = nullptr);
    ~NewNaborForm();
    void setNabor(Nabor* nabor);

private:
    void setupModel();
    void addModelItem(Detail* detail);

private slots:
    void on_pushButton_released();
    void on_buttonBox_accepted();
    void on_deleteButton_pressed();
    void clicked(QModelIndex indx);
    void doubleClicked(QModelIndex indx);

};

#endif // NEWNABORFORM_H
