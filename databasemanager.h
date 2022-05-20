#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "nabor.h"
#include "uchyot.h"

class DataBaseManager {
private:
    QSqlDatabase db;
    static DataBaseManager* singleton;

private:
    DataBaseManager();
    bool initDataBase();
    bool insertSettings();

public:
    static DataBaseManager* getInstanse();
    ~DataBaseManager();
    QList<Nabor*>* getNabor();
    QList<Uchyot*>* thenotorious();

public:
    bool insertNabor(Nabor* nabor);
    bool insertDetail(Detail* detail, int naborId);
    bool insertUchyot(Uchyot* uchyot);

    bool updateNabor(Nabor* upNabor);
    bool updateDetail(Detail* upDetail);
    bool updateUchyot(Uchyot* upUchyot);

    bool deleteNabor(Nabor* delNabor);
    bool deleteDetail(Detail* delDetail);
    bool deleteUchyot(Uchyot* delUchyot);
};

#endif // DATABASEMANAGER_H
