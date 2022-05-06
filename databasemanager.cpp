#include "databasemanager.h"
#include <QSqlDatabase>
#include <QDebug>

DataBaseManager* DataBaseManager::getInstanse(){
    if (singleton == nullptr) {
        singleton = new DataBaseManager();
    }
    return singleton;
}

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
    bool whatIsBull = query.exec("CREATE TABLE nabor(nabor_id integer PRIMATY KEY AUTOINCREMENT, nameNabor text NOT NULL, invent_Number text NOT NULL, price Float NOT NULL, FOREIGN KEY nabor_id REFERENCES nabor(id))");

    if(!whatIsBull){
        qDebug() <<"не уудаётся созд";
    }


    whatIsBull = query.exec("CREATE TABLE uchyot(uchyot_id integer PRIMATY KEY AUTOINCREMENT, kol_vo integer NOT NULL, date text NOT NULL, detail_id integer, FOREIGN KEY detail_id REFERENCES detail(detail_id))");

    if(!whatIsBull){
        qDebug() <<"не уудаётся созд";
    }

    whatIsBull = query.exec("CREATE TABLE detail(detail_id integer PRIMATY KEY AUTOINCREMENT, code integer NOT NULL, count integer NOT NULL,picture text ,name text NOT NULL, nabor_id integer, FOREIGN KEY nabor_id REFERENCES nabor(nabor_id))");

    if(!whatIsBull){
        qDebug() <<"не уудаётся созд";
    }
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
    return false;
}

bool DataBaseManager::insertDetail(Detail *detail){
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO detail (code, count, name) VALUES (:code, :count, :name)");
    query.bindValue(":code", detail->getCode());
    query.bindValue(":count", detail->getCount());
    query.bindValue(":name", detail->getName());
 //   query.bindValue(":picture", detail->getPicture().)
    bool whatIsBull = query.exec();
    if(whatIsBull){
        int a = query.lastInsertId().toInt();
        detail->setId(a);
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

















