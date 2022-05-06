#include "detail.h"

Detail::Detail()
{
    code = 0;
    count = 0;
    picture = nullptr;
    name = "";
    uchyot = nullptr;
    id = 0;
}

Detail::~Detail()
{
    delete picture;
    delete uchyot;
}

Detail::Detail(Detail& detail)
{
    code = detail.code;
    count = detail.count;
    picture = detail.picture;
    name = detail.name;
    uchyot = detail.uchyot;
}

int Detail::getCode()
{
    return code;
}

int Detail::getCount()
{
    return count;
}

QImage* Detail::getPicture()
{
    return picture;
}

QString Detail::getName()
{
    return name;
}

QList<Uchyot>* Detail::getUcyot()
{
    return uchyot;
}

int Detail::getId(){
    return id;
}

/*  .........................................  */

void Detail::setCode(int code)
{
    this->code = code;
}

void Detail::setCount(int count)
{
    this->count = count;
}

void Detail::setName(QString name)
{
    this->name = name;
}

void Detail::setPicture(QImage* picture)
{
    this->picture = picture;
}

void Detail::setUchyot(QList<Uchyot>* uchyot)
{
    this->uchyot = uchyot;
}

void Detail::setId(int id){
    this->id = id;
}
