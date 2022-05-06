#include "mainwindow.h"

#include <QApplication>
#include "databasemanager.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    DataBaseManager* db = DataBaseManager::getInstanse();
    return a.exec();
}
