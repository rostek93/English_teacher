/**
 * @file AddWordWindow.cpp
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Implementation of the AddWordWindow class methods.
 */


#include "AddWordWindow.h"
#include "ui_AddWordWindow.h"
#include <QMessageBox>

using namespace std;

AddWordWindow::AddWordWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWordWindow)
{
    ui->setupUi(this);
}

AddWordWindow::~AddWordWindow()
{
    delete ui;
}

void AddWordWindow::on_cancel_button_clicked()
{
    this->close();
}

void AddWordWindow::on_save_button_clicked()
{
    if (ui->pol_word_edit->displayText() == "" || ui->eng_word_edit->displayText() == "")
        QMessageBox::about(this, "Blad", "Wymagane pola: Slowko i Polskie znaczenie");
    else {
        QString pol = ui->pol_word_edit->displayText();
        QString eng = ui->eng_word_edit->displayText();
        QString sentence = ui->sentence_edit->displayText();
        QString synonyms = ui->synonyms_edit->displayText();
        int type = 0;

        if (sentence != "")
            type += 1;
        if (synonyms != "")
            type += 2;


        dBase = "dane.db";
        df.addWord(dBase, type, pol, eng, sentence, synonyms);

    }

    ui->pol_word_edit->clear();
    ui->eng_word_edit->clear();
    ui->sentence_edit->clear();
    ui->synonyms_edit->clear();
}
