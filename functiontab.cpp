#include "functiontab.h"

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
        rez =
    }
}

