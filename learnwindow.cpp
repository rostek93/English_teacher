/**
 * @file LearnWindow.cpp
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Implementation of the LearnWindow class methods.
 */

#include "LearnWindow.h"
#include "ui_LearnWindow.h"
#include <QMessageBox>

using namespace std;


LearnWindow::LearnWindow(QWidget *parent, int number) :
    QDialog(parent),
    ui(new Ui::LearnWindow)
{
    ui->setupUi(this);

    dBase="dane.db";
    df.loadWords(dBase, number);

    words_to_learn = df.vNew_words.size();
    learned_words_counter = 0;
    words_to_repeat = df.vRepetition_words.size();
    repeated_words_counter = 0;

    if (number > words_to_learn)
        QMessageBox::about(this, "Brak nowych slowek", "Nowych slowek jest mniej");

    ui->correctly_button->hide();
    ui->almost_button->hide();
    ui->incorrectly_button->hide();
    ui->eng_word_label->hide();
    ui->sentence_label->hide();
    ui->lcd_new_number->display(learned_words_counter);
    ui->lcd_repeat_number->display(learned_words_counter);
    ui->new_words_label->setText("Nowe słowa na dzis: " + QString::number(words_to_learn));
    ui->repeat_words_label->setText("Słowa do powtorki: " + QString::number(words_to_repeat));

    getWords();
}


LearnWindow::~LearnWindow()
{
    delete ui;
}

void LearnWindow::on_check_button_clicked()
{
    ui->check_button->hide();
    ui->correctly_button->show();
    ui->almost_button->show();
    ui->incorrectly_button->show();
    ui->eng_word_label->show();

    if (df.vRepetition_words.size() != 0)
        if (df.vRepetition_words.front()->getSentence() != "")
            ui->sentence_label->show();

    if (df.vNew_words.size() != 0)
        if (df.vNew_words.front()->getSentence() != "")
            ui->sentence_label->show();
}

void LearnWindow::on_correctly_button_clicked()
{
    if(df.vRepetition_words.size() > 0) {
        ++repeated_words_counter;
        df.updateWords(dBase, df.vRepetition_words.front());
        df.vRepetition_words.erase(df.vRepetition_words.begin());
        if(df.vRepetition_words.size() > 0)
            df.vRepetition_words.front()->show(ui);
    }
    else if (df.vNew_words.size() > 0) {
        ++learned_words_counter;
        df.updateWords(dBase, df.vNew_words.front());
        df.vNew_words.erase(df.vNew_words.begin());
        if (df.vNew_words.size() > 0)
            df.vNew_words.front()->show(ui);
    }

    ui->lcd_new_number->display(learned_words_counter);
    ui->lcd_repeat_number->display(repeated_words_counter);

    ui->check_button->show();
    ui->correctly_button->hide();
    ui->almost_button->hide();
    ui->incorrectly_button->hide();

    if(repeated_words_counter == words_to_repeat && learned_words_counter == words_to_learn) {
        QMessageBox::about(this, "Koniec", "Nauczyles sie slowka na dzis");
        this->close();
    }
    else
        getWords();

}

void LearnWindow::on_incorrectly_button_clicked()
{
    if(df.vRepetition_words.size() > 0) {
        PtrAbstWord tmp = df.vRepetition_words.at(0);
        tmp->changeScore(2);
        df.vRepetition_words.erase(df.vRepetition_words.begin());
        df.vRepetition_words.push_back(tmp);
        df.vRepetition_words.front()->show(ui);
    }
    else if (df.vNew_words.size() > 0) {
        PtrAbstWord tmp = df.vNew_words.at(0);
        tmp->changeScore(2);
        df.vNew_words.erase(df.vNew_words.begin());
        df.vNew_words.push_back(tmp);
        df.vNew_words.front()->show(ui);
    }

    ui->check_button->show();
    ui->correctly_button->hide();
    ui->almost_button->hide();
    ui->incorrectly_button->hide();
    ui->eng_word_label->hide();
    ui->sentence_label->hide();
}

void LearnWindow::on_almost_button_clicked()
{
    if(df.vRepetition_words.size() > 0) {
        PtrAbstWord tmp = df.vRepetition_words.at(0);
        tmp->changeScore(1);
        df.vRepetition_words.erase(df.vRepetition_words.begin());
        df.vRepetition_words.push_back(tmp);
        df.vRepetition_words.front()->show(ui);
    }
    else if (df.vNew_words.size() > 0) {
        PtrAbstWord tmp = df.vNew_words.at(0);
        tmp->changeScore(1);
        df.vNew_words.erase(df.vNew_words.begin());
        df.vNew_words.push_back(tmp);
        df.vNew_words.front()->show(ui);
    }

    ui->check_button->show();
    ui->correctly_button->hide();
    ui->almost_button->hide();
    ui->incorrectly_button->hide();
    ui->eng_word_label->hide();
    ui->sentence_label->hide();
}

void LearnWindow::getWords() {
    if (df.vRepetition_words.size()>0)
        df.vRepetition_words.front()->show(ui);
    else
        df.vNew_words.front()->show(ui);
}


