#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "functiontab.h"
#include "lexicographicorder.h"
#include "productioninfo.h"

#include <algorithm>
#include <set>
#include <QSet>

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
    heading <<  "X" << "Result";
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
    ui->minLineEdit->setText(QString::number(std::min_element(results.begin(), results.end()) - results.begin() + 1));
    ui->maxLineEdit->setText(QString::number(std::max_element(results.begin(), results.end()) - results.begin() + 1));
}

void MainWindow::on_lexicographicalOrderButton_clicked()
{
    QString inputData = "C C++ Java Python Perl  R Matlab Ruby  JavaScript PHP AAA AAAB A AA";
    auto listOfWords = inputData.split(' ');
    listOfWords.removeAll(" ");
    auto vectorOfWords = listOfWords.toVector();
    std::sort(vectorOfWords.begin(), vectorOfWords.end());
    ui->lexicographicalPlainTextEdit->clear();
    foreach(auto item, vectorOfWords)
    {
        ui->lexicographicalPlainTextEdit->appendPlainText(item);
    }
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if (index != 3)
        return;
    std::vector <ProductionInfo> masOfProducts;
    for(int i = 0; i < 30; i++)
    {
        masOfProducts.push_back(ProductionInfo());
    }
    std::set <ProductionInfo> setOfProducts(masOfProducts.begin(), masOfProducts.end());

    ui->productionInfoTable->setColumnCount(2);
    ui->productionInfoTable->setRowCount(setOfProducts.size());
    QStringList heading;
    heading << "Product code" << "Total";
    ui->productionInfoTable->setHorizontalHeaderLabels(heading);

    for (auto it = setOfProducts.begin() ; it != setOfProducts.end() ; it++) {
        ui->productionInfoTable->setItem(int(it - setOfProducts.begin()), 0
                                 , (new QTableWidgetItem(QString::number(*it->code()))));
        ui->productionInfoTable->setItem(i, 1
                                 , (new QTableWidgetItem(QString::number(*it))));
    }

}
