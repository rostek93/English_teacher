/**
 * @file LearnWindow.cpp
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Implementation of the WordSentence class methods.
 */

#include "WordSentence.h"

using namespace std;

WordSentence::WordSentence() {}

WordSentence::WordSentence(PtrAbstWord dec, string sentence, int id):WordDecorator(dec,id), sentence(sentence) {}

WordSentence::~WordSentence(){}

string WordSentence::getSentence() const {
    return sentence;
}

string WordSentence::getSynonyms() const {
    return dec->getSynonyms();
}

void WordSentence::show(Ui::LearnWindow *ui) {
    WordDecorator::show(ui);

    ui->sentence_label->setText(sentence.c_str());
    ui->sentence_label->hide();
    ui->sentence_label_2->show();
}
