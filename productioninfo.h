#ifndef PRODUCTIONINFO_H
#define PRODUCTIONINFO_H

#include <QDate>

struct ProductionInfo
{
    QDate __date;
    QString __title;
    int __code;
    int __count;

public:
    ProductionInfo();
    ProductionInfo(QDate date, QString title, int code, int count);

    friend bool operator < (const ProductionInfo &a, const ProductionInfo &b);

};

#endif // PRODUCTIONINFO_H
