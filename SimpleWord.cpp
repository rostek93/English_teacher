/**
 * @file LearnWindow.cpp
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Implementation of the SimpleWord class methods.
 */

#include "SimpleWord.h"

using namespace std;

SimpleWord::SimpleWord():AbstractWord() {}

SimpleWord::SimpleWord(int id, string plWord, string engWord, int interval, double efactor):AbstractWord(id){
    this->plWord = plWord;
    this->engWord = engWord;
    this->interval = interval;
    this->efactor = efactor;
    this->score = 5;
}

SimpleWord::~SimpleWord(){}

string SimpleWord::getEngWord() const {
    return engWord;
}

string SimpleWord::getPlWord() const {
    return plWord;
}

string SimpleWord::getSentence() const {
   return "";
}

string SimpleWord::getSynonyms() const {
    return "";
}

int SimpleWord::getInterval() const {
    return interval;
}

double SimpleWord::getEfactor() const {
    return efactor;
}

void SimpleWord::algorithm() {
    score = score>0 ? score : 0;

    if(interval == 0) {
       interval = score+1;
       efactor = 2.5;
    }
    else{
        if (score < 3)
            interval = score==2 ? 5 : 2;
        else
            interval=interval*efactor;

        efactor=efactor+(0.1-(5-score)*(0.08+(5-score)*0.02));
        if(efactor<1.3){
            efactor=1.3;
        }
    }

}

void SimpleWord::show(Ui::LearnWindow* ui) {
    ui->pl_word_label->setText(plWord.c_str());
    ui->eng_word_label->setText(engWord.c_str());
    ui->eng_word_label->hide();
    ui->synonym_label->hide();
    ui->synonym_label_2->hide();
    ui->sentence_label->hide();
    ui->sentence_label_2->hide();
}

void SimpleWord::changeScore(const int s) {
    score -= s;
}

int SimpleWord::getId() const {
    return id;
}
