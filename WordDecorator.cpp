/**
 * @file LearnWindow.cpp
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Implementation of the WordDecorator class methods.
 */

#include "WordDecorator.h"

using namespace std;

WordDecorator::WordDecorator():AbstractWord() {}

WordDecorator::WordDecorator(PtrAbstWord w):AbstractWord(), dec(w) {}

WordDecorator::WordDecorator(PtrAbstWord w, int i):AbstractWord(i), dec(w) {}

WordDecorator::~WordDecorator() {}

string WordDecorator::getEngWord() const {
    return dec->getEngWord();
}

string WordDecorator::getPlWord() const {
    return dec->getPlWord();
}

int WordDecorator::getInterval() const {
    return dec->getInterval();
}

double WordDecorator::getEfactor() const {
    return dec->getEfactor();
}

void WordDecorator::algorithm() {
    dec->algorithm();
}

void WordDecorator::show(Ui::LearnWindow *ui) {
    dec->show(ui);
}

void WordDecorator::changeScore(const int s) {
    dec->changeScore(s);
}

int WordDecorator::getId() const {
    return dec->getId();
}
