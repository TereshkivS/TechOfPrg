#include "strichka.h"

#include <QString>
#include <QRegExp>

Strichka::Strichka(QString s1)
{
    s1.remove('.');
    auto list = s1.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    list.removeAll(" ");

    for(auto &&var : list)
    {
        strichas.append(var);
    }
}

void Strichka::AddAString(QString str)
{
    strichas.append(str);
}

QString Strichka::findCharactersInSentences()
{
    QString result;
    foreach (QString temp, strichas) {
        if(temp.count('d', Qt::CaseSensitivity::CaseInsensitive) == 2){
            result.append(temp + " ");
        }
    }
    return result;
}
