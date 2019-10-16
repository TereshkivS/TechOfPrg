#ifndef LEXICOGRAPHICORDER_H
#define LEXICOGRAPHICORDER_H

#include <QString>
#include <QStringList>

class LexicographicOrder
{
public:
    LexicographicOrder();

public:
    static QStringList DoLexicOrder(QString inputstring);
};

#endif // LEXICOGRAPHICORDER_H
