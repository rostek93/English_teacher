/**
 * @file mainwindow.cpp
 * @author Damian Pobrotyn , Kamil Rostecki
 * @brief Implementation of the MainWindow Methods.
 */

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DataBaseWords.h"

#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->number_words_label->setText(str.setNum(ui->number_words_slider->value()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionZamknij_triggered()
{
  close();
}


void MainWindow::on_learn_button_clicked()
{
    if (lw == nullptr) {
        lw = (new LearnWindow(this,ui->number_words_slider->value()));
        lw->setAttribute(Qt::WA_DeleteOnClose, true);
        lw->show();
    }
}

void MainWindow::on_add_word_button_clicked()
{
    if (aww == nullptr) {
        aww = (new AddWordWindow(this));
        aww->setAttribute(Qt::WA_DeleteOnClose, true);
        aww->show();
    }
}

void MainWindow::on_number_words_slider_actionTriggered(int action)
{
    ui->number_words_label->setText(str.setNum(action));
}


void MainWindow::on_number_words_slider_valueChanged(int value)
{
    ui->number_words_label->setText(str.setNum(value));
}


void MainWindow::on_exit_button_clicked()
{
    QApplication::quit();
}


void MainWindow::on_words_button_clicked()
{
    if (lw == nullptr && aww == nullptr) {
        DataBaseWords *dbw = new DataBaseWords(this);
        dbw->show();
    }
    else if (lw != nullptr)
        QMessageBox::about(this, "Blad", "Musisz najpierw zakonczyć nauke");
    else if (aww != nullptr)
        QMessageBox::about(this, "Blad", "Musisz najpierw zakonczyć dodawnie słow");
}

void MainWindow::on_schedule_button_clicked()
{
    CalendarWindow *cw = new CalendarWindow(this);
    cw->show();
}

void MainWindow::on_clear_button_clicked()
{
    QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Resetowanie ustawien", "Czy na pewno chcesz usunac caly postep nauki?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
         dBase = "dane.db";
        df.resetUser(dBase);
     }
}
