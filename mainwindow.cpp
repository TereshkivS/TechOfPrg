#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "functiontab.h"

#include <algorithm>

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

    auto resTable = functionTab->CalculateTab();

    ui->resultTable->setColumnCount(2);
    ui->resultTable->setRowCount(resTable.size());
    QStringList heading;
    heading <<  "Delta" << "Result";
    ui->resultTable->setHorizontalHeaderLabels(heading);
    for (int i = 0 ; i < resTable.size() ; i++) {
        ui->resultTable->setItem(i, 0
                                 , (new QTableWidgetItem(QString::number(resTable.at(i).first))));
        ui->resultTable->setItem(i, 1
                                 , (new QTableWidgetItem(QString::number(resTable.at(i).second))));
    }
    std::vector<double> results;
    foreach (auto item, resTable) {
        results.push_back(item.second);
    }
    ui->minLineEdit->setText(QString::number(std::min_element(results.begin(), results.end()) - results.begin()));
    ui->maxLineEdit->setText(QString::number(*std::min_element(results.begin(), results.end())));
}
