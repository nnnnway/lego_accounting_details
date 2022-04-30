#ifndef ADDNEWDETAIL_H
#define ADDNEWDETAIL_H

#include <QDialog>

namespace Ui {
class AddNewDetail;
}

class AddNewDetail : public QDialog {
    Q_OBJECT

public:
    explicit AddNewDetail(QWidget* parent = nullptr);
    ~AddNewDetail();

private:
    Ui::AddNewDetail* ui;
};

#endif // ADDNEWDETAIL_H
