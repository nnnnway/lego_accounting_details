#include "nabor.h"

Nabor::Nabor()
{
    details = nullptr;
    nameNabor = "";
    price = 0.0;
    invetn_Number = "";
    id = 0;
}

Nabor::~Nabor()
{
    delete details;
}

Nabor::Nabor(Nabor& nabor)
{
    details = nabor.details;
    nameNabor = nabor.nameNabor;
    price = nabor.price;
    invetn_Number = nabor.invetn_Number;
}

QList<Detail>* Nabor::getDetails()
{
    return details;
}

QString Nabor::getNameNabor()
{
    return nameNabor;
}

float Nabor::getPrice()
{
    return price;
}

QString Nabor::getInvetn_Number()
{
    return invetn_Number;
}

int Nabor::getId(){
    return id;
}

/* ............................... */

void Nabor::setId(int id){
    this->id = id;
}

void Nabor::setDetails(QList<Detail>* details)
{
    this->details = details;
}

void Nabor::setNameNabor(QString nameNabor)
{
    this->nameNabor = nameNabor;
}

void Nabor::setPrice(float price)
{
    this->price = price;
}

void Nabor::setInvetn_Number(QString invetn_Number)
{
    this->invetn_Number = invetn_Number;
}
