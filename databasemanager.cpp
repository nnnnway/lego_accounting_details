#include "databasemanager.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QFile>

#define DELETE_FILE

DataBaseManager* DataBaseManager::singleton = nullptr;

DataBaseManager* DataBaseManager::getInstanse(){
    if (DataBaseManager::singleton == nullptr) {
        DataBaseManager::singleton = new DataBaseManager();
    }
    return DataBaseManager::singleton;
}

DataBaseManager::DataBaseManager()
{
#ifdef DELETE_FILE
    QFile file("./testDB.db");
    if (file.exists()){
        file.remove();
    }
#endif

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");

    if(db.open()){
        qDebug() << "open";
    }else{
        qDebug() << "no open";
    }
    initDataBase();
}

DataBaseManager::~DataBaseManager(){
    db.commit();
    db.close();
}

bool DataBaseManager::initDataBase(){
    QSqlQuery query = QSqlQuery(db);

    bool whatIsBull = query.exec("CREATE TABLE nabor(nabor_id INTEGER, "
                                 "nameNabor TEXT NOT NULL, "
                                 "invent_Number TEXT NOT NULL, "
                                 "price float NOT NULL, "
                                 "PRIMARY KEY(nabor_id AUTOINCREMENT))");
    if(!whatIsBull){
        qDebug() << "ERROR CREATE TABLE nabor" << query.lastError().databaseText();
        return false;
    }

    whatIsBull = query.exec("CREATE TABLE detail(detail_id INTEGER, "
                            "code INTEGER NOT NULL, "
                            "count INTEGER NOT NULL, "
                            "picture TEXT NOT NULL DEFAULT 'no_name.jpg', "
                            "name TEXT NOT NULL, "
                            "nabor_id INTEGER, "
                            "PRIMARY KEY(detail_id AUTOINCREMENT), "
                            "FOREIGN KEY (nabor_id) REFERENCES nabor(nabor_id))");
    if(!whatIsBull){
       qDebug() << "ERROR CREATE TABLE detail" << query.lastError().databaseText();
       return false;
    }

    whatIsBull = query.exec("CREATE TABLE uchyot(uchyot_id INTEGER, "
                            "kol_vo INTEGER NOT NULL, "
                            "date TEXT NOT NULL, "
                            "detail_id INTEGER, "
                            "PRIMARY KEY(uchyot_id AUTOINCREMENT), "
                            "FOREIGN KEY (detail_id) REFERENCES detail(detail_id))");
    if(!whatIsBull){
       qDebug() << "ERROR CREATE TABLE uchyot" << query.lastError().databaseText();
       return false;
    }
    return true;
}

/* INS INS INS INS INS INS INS */

bool DataBaseManager::insertNabor(Nabor *nabor){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO nabor (nameNabor, invent_Number, price) VALUES (:nameNabor, :invent_Number, :price)");
    query.bindValue(":nameNabor", nabor->getNameNabor());
    query.bindValue(":invent_Number", nabor->getInvetn_Number());
    query.bindValue(":price", nabor->getPrice());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        int a = query.lastInsertId().toInt();
        nabor->setId(a);
        return true;
    }
    qDebug() << "ERROR RECORD nabor" << query.lastError().databaseText();
    return false;
}

bool DataBaseManager::insertDetail(Detail *detail){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO detail (code, count, name, picture) VALUES (:code, :count, :name, :picture)");
    query.bindValue(":code", detail->getCode());
    query.bindValue(":count", detail->getCount());
    query.bindValue(":name", detail->getName());
//    query.bindValue(":picture", detail->getPicture()->fileName());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        int a = query.lastInsertId().toInt();
        detail->setId(a);
        return true;
    }
    qDebug() << "ERROR RECORD detail" << query.lastError().databaseText();
    return false;
}

bool DataBaseManager::insertUchyot(Uchyot* uchyot){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO uchyot (kol_vo, date) VALUES (:kol_vo, :date)");
    query.bindValue(":kol_vo", uchyot->getKol_vo());
    query.bindValue(":date", uchyot->getDate());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        int a = query.lastInsertId().toInt();
        uchyot->setId(a);
        return true;
    }
    return false;
}

/* UPD UPD UPD UPD UPD UPD UPD UPD */

bool DataBaseManager::updateNabor(Nabor* upNabor){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("UPDATE nabor SET nameNabor = :nameNabor, invetn_Number = :invetn_Number, price = :price WHERE nabor_id = :nabor_id");
    query.bindValue(":nameNabor", upNabor->getNameNabor());
    query.bindValue(":invent_Number", upNabor->getInvetn_Number());
    query.bindValue(":price", upNabor->getPrice());
    query.bindValue(":nabor_id", upNabor->getId());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}

bool DataBaseManager::updateDetail(Detail* upDetail){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("UPDATE detail SET code = :code, count = :count, name = :name WHERE detail_id = :detail_id");
    query.bindValue(":code", upDetail->getCode());
    query.bindValue(":count", upDetail->getCount());
    query.bindValue(":name", upDetail->getName());
    query.bindValue(":detail_id", upDetail->getId());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}

bool DataBaseManager::updateUchyot(Uchyot* upUchyot){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("UPDATE uchyot SET kol_vo = :kol_vo, date = :date WHERE uchot_id = :uchyot_id");
    query.bindValue(":kol_vo", upUchyot->getKol_vo());
    query.bindValue(":date", upUchyot->getDate());
    query.bindValue(":uchyot_id", upUchyot->getId());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}

/* DEL DEL DEL DEL DEL DEL DEL DEL */

bool DataBaseManager::deleteNabor(Nabor* delNabor){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("DELETE FROM nabor WHERE nabor_id = :nabor_id");
    query.bindValue(":nabor_id", delNabor->getId());

    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}

bool DataBaseManager::deleteDetail(Detail *delDetail){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("DELETE FROM detail WHERE detail_id = :detail_id");
    query.bindValue(":detail_id", delDetail->getId());

    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}

bool DataBaseManager::deleteUchyot(Uchyot* delUchyot){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("DELETE FROM uchyot WHERE uchyot_id = :uchyot_id");
    query.bindValue(":uchyot_id", delUchyot->getId());

    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}

















