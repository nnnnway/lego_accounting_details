#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>

#include "nabor.h"

class DataBaseManager
{
    QSqlDatabase db;
    static DataBaseManager* singleton;

    DataBaseManager();

public:
    static DataBaseManager* getInstanse();

    void initDataBase();

    bool insertNabor(Nabor* nabor);
    bool insertDetail(Detail* detail);
    bool insertUchyot(Uchyot* uchyot);

    bool updateNabor(Nabor* upNabor);
    bool updateDetail(Detail* upDetail);
    bool updateUchyot(Uchyot* upUchyot);


    bool deleteNabor(Nabor* delNabor);
    bool deleteDetail(Detail* delDetail);
    bool deleteUchyot(Uchyot* delUchyot);
};

#endif // DATABASEMANAGER_H
