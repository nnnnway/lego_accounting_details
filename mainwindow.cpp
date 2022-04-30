#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action, SIGNAL(triggered()), this, SLOT(onNewFormTap()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewFormTap()
{
    form = new NewNaborForm(this);
    form->show();
}
