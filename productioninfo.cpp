#include "productioninfo.h"
#include <QRandomGenerator>
#include <time.h>


ProductionInfo::ProductionInfo()
{
    QRandomGenerator random(time(NULL) + rand());
    __code = random.bounded(10);
    __date = QDate(2019, 10, random.bounded(1, 30));
    __title = QString::number(__code);
    __count = random.bounded(100);

}

ProductionInfo::ProductionInfo(QDate date, QString title, int code, int count)
    :__date(date), __title(title), __code(code), __count(count)
{

}

bool operator< (const ProductionInfo &a, const ProductionInfo &b)
{
    return a.__count < b.__count;
}


