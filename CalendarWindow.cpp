/**
 * @file LearnWindow.cpp
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Implementation of the CalendarWindow class methods.
 */

#include "CalendarWindow.h"
#include "ui_CalendarWindow.h"
#include <QStandardItemModel>
#include <QTableWidgetItem>

using namespace std;

CalendarWindow::CalendarWindow(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::CalendarWindow)
{
    ui->setupUi(this);

    dBase="dane.db";
    df.loadCalendar(dBase);

    int size = df.date_repetitions.size();

    QStandardItemModel *model = new QStandardItemModel(size,2,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Data")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Ilość słów")));

    int i=0;
    for (std::map<string,int>::iterator it=df.date_repetitions.begin(); it!=df.date_repetitions.end(); ++it) {
        model->setItem(i,0, new QStandardItem(QString::fromStdString(it->first)));
        model->setItem(i,1, new QStandardItem(QString::number(it->second)));
        ++i;
      }

    ui->table_view->setModel(model);
}

CalendarWindow::~CalendarWindow()
{
    delete ui;
}

void CalendarWindow::on_back_button_clicked()
{
    this->close();
}
