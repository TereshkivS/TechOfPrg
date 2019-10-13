#include "functiontab.h"
#include <math.h>

FunctionTab::FunctionTab(double a, double b, double delta, double k)
    :__a(a), __b(b), __delta(delta), __k(k)
{

}

QVector<QPair<double, double> > FunctionTab::CalculateTab()
{
    QVector<QPair<double, double>> funcResults;
    double rez;
    for(double x = __a; x < __b ; x += __delta)
    {
        rez = x * __k + tan(x);
        funcResults.append(QPair <double, double>(x, rez));
    }

    return funcResults;
}

