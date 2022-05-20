#ifndef UCHYOT_H
#define UCHYOT_H

#include <QDate>

class Uchyot {
    int kol_vo;
    QDate date;
    int id;

public:
    Uchyot();
    ~Uchyot();
    Uchyot(Uchyot& uchyot);
    Uchyot(int uchyot_id, int kol_vo, QString date);

    int getKol_vo();
    QDate getDate();
    int getId();

    void setKol_vo(int kol_vo);
    void setDate(QDate date);
    void setId(int id);
};

#endif // UCHYOT_H
