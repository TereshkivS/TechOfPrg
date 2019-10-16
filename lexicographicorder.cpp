#include "lexicographicorder.h"
#include <QDebug>

LexicographicOrder::LexicographicOrder()
{

}

QStringList LexicographicOrder::DoLexicOrder(QString inputstring)
{
    auto myList = inputstring.split(' ');
    myList.removeAll("");
    qDebug() << myList;
    return myList;
}
