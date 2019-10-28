#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "functiontab.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void reloadItemsInTable(int index, const QDate &date);

private slots:
    void on_calculateButton_clicked();

    void on_lexicographicalOrderButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;
    FunctionTab *functionTab;
};
#endif // MAINWINDOW_H
