/**
 * @file LearnWindow.cpp
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Implementation of the WordSynonyms class methods.
 */

#include "WordSynonyms.h"

using namespace std;

WordSynonyms::WordSynonyms() {}

WordSynonyms::WordSynonyms(PtrAbstWord dec, string synonyms, int id):WordDecorator(dec,id), synonyms(synonyms) {}

WordSynonyms::~WordSynonyms() {}

string WordSynonyms::getSentence() const {
    return dec->getSentence();
}

string WordSynonyms::getSynonyms() const {
    return synonyms;
}

void WordSynonyms::show(Ui::LearnWindow *ui) {
    WordDecorator::show(ui);

    ui->synonym_label->setText(synonyms.c_str());
    ui->synonym_label->show();
    ui->synonym_label_2->show();

}
