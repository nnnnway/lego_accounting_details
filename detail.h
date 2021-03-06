#ifndef DETAIL_H
#define DETAIL_H

#include "uchyot.h"
#include <QImage>
#include <QList>
#include <QString>

class Detail {

private:
    int id;
    int code;
    int count;
    QImage* picture;
    QString name;
    QList<Uchyot>* uchyot;

public:
    Detail();
    ~Detail();
    Detail(Detail& detail);

    int getCode();
    int getCount();
    QImage* getPicture();
    QString getName();
    QList<Uchyot>* getUcyot();
    int getId();

    void setCode(int code);
    void setCount(int count);
    void setPicture(QImage* picture);
    void setName(QString name);
    void setUchyot(QList<Uchyot>* uchyot);
    void setId(int id);
};

#endif // DETAIL_H
