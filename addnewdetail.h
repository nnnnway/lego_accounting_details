#ifndef ADDNEWDETAIL_H
#define ADDNEWDETAIL_H

#include <QDialog>
#include <QFile>

#include "detail.h"

namespace Ui {
class AddNewDetail;
}

class AddNewDetail : public QDialog {
    Q_OBJECT

private:
    Ui::AddNewDetail* ui;
    Detail* detail;
    QImage* img;

public:
    explicit AddNewDetail(QWidget* parent = nullptr);
    ~AddNewDetail();

    void setDetail(Detail* x);

    Detail* getDetail();

private:
    void hideAllError();

private slots:
    void on_select_image_pressed();
    void on_save_pressed();
    void on_close_pressed();
};

#endif // ADDNEWDETAIL_H
