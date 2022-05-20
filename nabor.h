#ifndef NABOR_H
#define NABOR_H

#include "detail.h"
#include <QList>
#include <QString>

class Nabor {
    QList<Detail*>* details;
    QString nameNabor;
    float price;
    QString invetn_Number;
    int id;

public:
    Nabor();
    ~Nabor();
    Nabor(Nabor& nabor);
    Nabor(int x, QString y, QString z, float t);

    QList<Detail*>* getDetails();
    QString getNameNabor();
    float getPrice();
    QString getInvetn_Number();
    int getId();

    void setDetails(QList<Detail*>* details);
    void setNameNabor(QString nameNabor);
    void setPrice(float price);
    void setInvetn_Number(QString invetn_Number);
    void setId(int id);
};

#endif // NABOR_H
