#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "functiontab.h"
#include "lexicographicorder.h"
#include "productioninfo.h"

#include <algorithm>
#include <set>
#include <QSet>
#include <QFile>
#include <QTextStream>
#include <QDebug>

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

void MainWindow::reloadItemsInTable(int index, const QDate &date)
{
    if (index != 2)
        return;

    std::vector <ProductionInfo> masOfProducts;

    /*use this*/
    QFile file("/home/serhii/TechonolyOfProgramming/inputdata");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream input(&file);
    QString line = input.readLine();
    while (!line.isNull()) {
        auto splitLines = line.split(' ');
        /*int day, month, year, code, count;
        QString title;
        year = splitLines.front().toInt();
        splitLines.pop_front();
        month = splitLines.front().toInt();
        splitLines.pop_front();
        day = splitLines.front().toInt();
        splitLines.pop_front();
        title = splitLines.back();
        splitLines.pop_front();
        code = splitLines.back().toInt();
        splitLines.pop_front();
        count = splitLines.back().toInt();
        splitLines.pop_front();
        masOfProducts.push_back(ProductionInfo(date, title, code, count));*/
        masOfProducts.push_back(ProductionInfo(QDate(splitLines.takeLast().toInt(), splitLines.takeLast().toInt(),splitLines.takeLast().toInt()),
                                               splitLines.takeLast(), splitLines.takeLast().toInt(), splitLines.takeLast().toInt()));
        line = input.readLine();
    }

    /*or this*/
    /*for(int i = 0; i < 30; i++)takeFirst
    {
        masOfProducts.push_back(ProductionInfo());
    }*/

    std::map<int, int> mapOfProducts;

    for (std::vector<ProductionInfo>::iterator it = masOfProducts.begin(); it != masOfProducts.end(); it ++) {
        if((*it).__date != date)
            continue;
        if(mapOfProducts.count((*it).__code) > 0)
        {
            mapOfProducts.find((*it).__code)->second += (*it).__count;
        }
        else {
            mapOfProducts.insert(std::pair<int, int>((*it).__code, (*it).__count));
        }
    }
    ui->productionInfoTable->setColumnCount(2);
    ui->productionInfoTable->setRowCount(mapOfProducts.size());
    QStringList heading;
    heading << "Product code" << "Total";
    ui->productionInfoTable->setHorizontalHeaderLabels(heading);
    auto iter = mapOfProducts.begin();
    for (int i = 0; i < mapOfProducts.size() ; i++, iter++) {
        ui->productionInfoTable->setItem(i, 0, (new QTableWidgetItem(QString::number((*iter).first))));
        ui->productionInfoTable->setItem(i, 1, (new QTableWidgetItem(QString::number((*iter).second))));
    }
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    reloadItemsInTable(2, date);
}
