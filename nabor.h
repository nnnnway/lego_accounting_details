#ifndef NABOR_H
#define NABOR_H

#include "detail.h"
#include <QList>
#include <QString>

class Nabor {
    QList<Detail>* details;
    QString nameNabor;
    float price;
    QString invetn_Number;

public:
    Nabor();
    ~Nabor();
    Nabor(Nabor& nabor);

    QList<Detail>* getDetails();
    QString getNameNabor();
    float getPrice();
    QString getInvetn_Number();

    void setDetails(QList<Detail>* details);
    void setNameNabor(QString nameNabor);
    void setPrice(float price);
    void setInvetn_Number(QString invetn_Number);
};

#endif // NABOR_H
