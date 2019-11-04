#ifndef STRICHKA_H
#define STRICHKA_H

#include <QVector>
#include <QString>

class Strichka
{
public:
    Strichka(QString);

    void AddAString(QString str);

    QString findCharactersInSentences();
private:
    QVector<QString> strichas;
};

#endif // STRICHKA_H
