#include "databasemanager.h"

#include <QSqlDatabase>
#include <QDebug>



DataBaseManager::DataBaseManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");

    if(db.open()){
        qDebug() << "open";
    }else{
        qDebug() << "no open";
    }
    initDataBase();
}

void DataBaseManager::initDataBase(){
    QSqlQuery query = QSqlQuery(db);
    bool whatIsBull = query.exec("CREATE TABLE nabor(nabor_id integer PRIMATY KEY AUTOINCREMENT, nameNabor text NOT NULL, invent_Number text NOT NULL, price Float NOT NULL)");

    if(!whatIsBull){
        qDebug() <<"не уудаётся созд";
    }

    whatIsBull = query.exec("CREATE TABLE uchyot(contact_id integer PRIMATY KEY AUTOINCREMENT, kol_vo integer NOT NULL, date text NOT NULL)");

    if(!whatIsBull){
        qDebug() <<"не уудаётся созд";
    }

    whatIsBull = query.exec("CREATE TABLE detail(contact_id integer PRIMATY KEY AUTOINCREMENT, code integer NOT NULL, count integer NOT NULL, picture text ,name text NOT NULL)");

    if(!whatIsBull){
        qDebug() <<"не уудаётся созд";
    }
}


bool DataBaseManager::insertNabor(Nabor* nabor){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO nabor (nameNabor, invent_Number, price) VALUES (:nameNabor, :invent_Number, :price)");
    query.bindValue(":nameNabor", nabor->getNameNabor());
    query.bindValue(":invetn_Number", nabor->getInvetn_Number());
    query.bindValue(":price", nabor->getPrice());
    bool whatIsBull = query.exec();
    if(whatIsBull) {
        int a = query.lastInsertId().toInt();
        nabor->setId(a);
        return true;
    }
    return false;
}

bool DataBaseManager::insertDetail(Detail* detail){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO detail (code, count, name, ucyot) VALUES (:code, :count, :name)");
    query.bindValue(":code", detail->getCode());
    query.bindValue(":count", detail->getCount());
    query.bindValue(":name", detail->getName());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}

bool DataBaseManager::insertUchyot(Uchyot* uchyot){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO uchyot (kol_vo, date) VALUES (:kol_vo, :date)");
    query.bindValue(":kol_vo", uchyot->getKol_vo());
    query.bindValue(":date", uchyot->getDate());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}


/* UPD UPD UPD UPD UPD UPD */


bool DataBaseManager::updateNabor(Nabor* upNabor){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("UPDATE nabor SET nameNabor = :nameNabor, invent_Number = :invetn_Number, price = :price WHERE nabor_id = :nabor_id");
    query.bindValue(":nameNabor", upNabor->getNameNabor());
    query.bindValue(":invetn_Number", upNabor->getInvetn_Number());
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
    query.prepare("UPDATE detail SET ContactName = 'code', 'count', 'name'");
    query.bindValue(":code", upDetail->getCode());
    query.bindValue(":count", upDetail->getCount());
    query.bindValue(":name", upDetail->getName());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}

bool DataBaseManager::updateUchyot(Uchyot* upUchyot){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("UPDATE uchyot SET ContactName = 'kol_vo', 'date'");
    query.bindValue(":kol_vo", upUchyot->getKol_vo());
    query.bindValue(":date", upUchyot->getDate());
    bool whatIsBull = query.exec();
    if(whatIsBull){
        return true;
    }
    return false;
}


/* DEL DEL DEL DEL DEL DEL */


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







