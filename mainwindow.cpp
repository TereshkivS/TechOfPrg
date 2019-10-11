#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "functiontab.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calculateButton_clicked()
{
    functionTab = new FunctionTab(ui->aLineEdit->text().toDouble()
                                  ,ui->bLineEdit->text().toDouble()
                                  ,ui->deltaLineEdit->text().toDouble()
                                  ,ui->kLineEdit->text().toDouble());

}
