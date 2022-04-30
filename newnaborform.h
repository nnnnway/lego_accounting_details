#ifndef NEWNABORFORM_H
#define NEWNABORFORM_H

#include "addnewdetail.h"
#include <QDialog>

namespace Ui {
class NewNaborForm;
}

class NewNaborForm : public QDialog {
    Q_OBJECT

public:
    explicit NewNaborForm(QWidget* parent = nullptr);
    ~NewNaborForm();

private:
    Ui::NewNaborForm* ui;
    AddNewDetail* form;

private slots:
    void on_pushButton_released();
    void on_lineEdit_accepted();
};

#endif // NEWNABORFORM_H
