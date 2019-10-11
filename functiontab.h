#ifndef FUNCTIONTAB_H
#define FUNCTIONTAB_H

#include <QVector>
#include <QPair>

class FunctionTab
{
private:
    double __a;
    double __b;
    double __delta;
    double __k;
public:
    FunctionTab(double a, double b, double delta, double k);

public:
    QVector<QPair<double, double>> CalculateTab();
};

#endif // FUNCTIONTAB_H
