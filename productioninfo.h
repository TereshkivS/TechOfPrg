#ifndef PRODUCTIONINFO_H
#define PRODUCTIONINFO_H

#include <QDate>

class ProductionInfo
{
private:
    QDate __date;
    QString __title;
    int __code;
    int __count;
public:
    ProductionInfo();
    ProductionInfo(QDate date, QString title, int code, int count);

    int code() const;
};

#endif // PRODUCTIONINFO_H
