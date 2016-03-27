/**
 * @file AbstractWord.h
 * @author Kamil Rostecki and Damian Pobrotyn
 * @brief Definition of the class AbstractWord.
 */

#ifndef ABSTRACTWORD_H
#define ABSTRACTWORD_H

#include <fstream>
#include "ui_LearnWindow.h"


/**
 * @brief
 * Abstract class, from which inherit classes: SimpleWord and WordDecorator.
 */
class AbstractWord
{
public:
    AbstractWord();

    /**
     * @brief
     * Constructor.
     * @param i is id word in the databse
     */
    AbstractWord(int i);

    ~AbstractWord();

    /**
     * @brief
     * Returns string, which is english word
     */
    virtual std::string getEngWord() const = 0;

    /**
     * @brief
     * Returns string, which is polish word
     */
    virtual std::string getPlWord() const = 0;

    /**
     * @brief
     * Returns string, which is sentence
     */
    virtual std::string getSentence() const = 0;

    /**
     * @brief
     * Returns string, which is synonyms
     */
    virtual std::string getSynonyms() const = 0;

    /**
     * @brief
     * Returns int, which is last interval between repeats
     */
    virtual int getInterval() const = 0;

    /**
     * @brief
     * Returns double, which is E-Factor
     */
    virtual double getEfactor() const = 0;

    /**
     * @brief
     * Compute interval and efactor value.
     * We use and modified algorithm author P.Wozniak (http://www.supermemo.com/english/ol/sm2.htm)
     */
    virtual void algorithm() = 0;

    /**
     * @brief
     * Method display contents word in learn window, e.g. polish word, english word and sentence.
     * @param *ui is pointer to learn window
     */
    virtual void show(Ui::LearnWindow *ui) = 0;

    /**
     * @brief
     * Compute quality response if user click correctly button score is 5, each click almost correctly button decrease
     * score about 1 and each click incorrectly button decrease about 2.
     * @param i is value of which score(5) is decrease
     */
    virtual void changeScore(const int s) = 0;

    /**
     * @brief
     * Returns int, which is id word
     */
    virtual int getId() const = 0;

    /**
     * @brief
     * id word in the database.
     */
    int id;
};

#endif // ABSTRACTWORD_H
