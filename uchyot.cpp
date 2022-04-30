#include "uchyot.h"

Uchyot::Uchyot()
{
    kol_vo = 0;
    date = QDate(1970, 01, 01);
}

Uchyot::~Uchyot()
{
}

Uchyot::Uchyot(Uchyot& uchyot)
{
    kol_vo = uchyot.kol_vo;
    date = uchyot.date;
}

int Uchyot::getKol_vo()
{
    return kol_vo;
}

QDate Uchyot::getDate()
{
    return date;
}

/* .................... */

void Uchyot::setKol_vo(int kol_vo)
{
    this->kol_vo = kol_vo;
}

void Uchyot::setDate(QDate date)
{
    this->date = date;
}
