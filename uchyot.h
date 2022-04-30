#ifndef UCHYOT_H
#define UCHYOT_H

#include <QDate>

class Uchyot {
    int kol_vo;
    QDate date;

public:
    Uchyot();
    ~Uchyot();
    Uchyot(Uchyot& uchyot);

    int getKol_vo();
    QDate getDate();

    void setKol_vo(int kol_vo);
    void setDate(QDate date);
};

#endif // UCHYOT_H
