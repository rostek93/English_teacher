/**
 * @file LearnWindow.cpp
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Implementation of the DataBaseWords class methods.
 */

#include "DataBaseWords.h"
#include "ui_DataBaseWords.h"
#include <QStandardItemModel>
#include <QTableWidgetItem>

using namespace std;

DataBaseWords::DataBaseWords(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::DataBaseWords)
{
    ui->setupUi(this);

    refresh();

}

DataBaseWords::~DataBaseWords()
{
    delete ui;
}

void DataBaseWords::refresh() {
    dBase="dane.db";
    df.loadAllWords(dBase);

    int size = df.vAll_words.size();

    QStandardItemModel *model = new QStandardItemModel(size,3,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("   ")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("polskie słowo")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("angielskie słowo")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("zdanie")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("synonimy")));

    for (size_t i=0; i<df.vAll_words.size(); ++i) {
        QStandardItem *itm = new QStandardItem();
        itm->setFlags(itm->flags() | Qt::ItemIsUserCheckable);
        itm->setCheckState(Qt::Unchecked);
        model->setItem(i,0,itm);
        model->setItem(i,1, new QStandardItem(QString::fromStdString(df.vAll_words.at(i)->getPlWord())));
        model->setItem(i,2, new QStandardItem(QString::fromStdString(df.vAll_words.at(i)->getEngWord())));
        model->setItem(i,3, new QStandardItem(QString::fromStdString(df.vAll_words.at(i)->getSentence())));
        model->setItem(i,4, new QStandardItem(QString::fromStdString(df.vAll_words.at(i)->getSynonyms())));
    }
    ui->table_widget->setModel(model);
}

void DataBaseWords::on_delete_button_clicked()
{
    QModelIndex index;

    for (size_t i=0; i<df.vAll_words.size(); i++) {
        index = ui->table_widget->model()->index(i,0, QModelIndex());
        if(index.data(Qt::CheckStateRole) == Qt::Checked){
            int id = df.vAll_words.at(i)->getId();
            df.removeWord(dBase, id);
        }
    }
    df.vAll_words.clear();
    refresh();

}

void DataBaseWords::on_back_button_clicked()
{
    this->close();
}
