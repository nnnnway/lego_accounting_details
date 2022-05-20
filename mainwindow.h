#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "nabor.h"
#include "newnaborform.h"
#include <QItemSelection>
#include <QMainWindow>
#include <QModelIndex>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow* ui;
    QList<Nabor*>* factory;
    NewNaborForm* form;
    QStandardItemModel* warThunder;
    int idNaborSelect;
    QModelIndex index;

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    void setupModel();
    void addModelItem(Nabor* nabor);

private slots:
    void onNewFormTap();
    void doubleClicked(QModelIndex index);
    void clicked(QModelIndex index);
    void on_editNabor_pressed();
    void on_deleteNabor_pressed();
};
#endif // MAINWINDOW_H
