/**
 * @file AbstractWord.h
 * @author Kamil Rostecki and Damian Pobrotyn
 * @brief Definition of the class SimpleWord.
 */


#ifndef SIMPLEWORD_H
#define SIMPLEWORD_H

#include "AbstractWord.h"

/**
 * @brief
 * class representing simple word contains english and polish word
 */
class SimpleWord: public AbstractWord
{
public:
    SimpleWord();

    /**
     * @brief
     * Constructor creating new simple words.
     * @param i is id word in the databse
     * @param plWord is polish word with the database
     * @param engWord is english word with the database
     * @param interval is interval value with the database
     * @param efactor is E-Factor value with the database
     */
    SimpleWord(int id, std::string plWord, std::string engWord, int interval=0, double efactor=0);

    ~SimpleWord();

    std::string getEngWord() const;

    std::string getPlWord() const;

    std::string getSentence() const;

    std::string getSynonyms() const;

    int getInterval() const;

    double getEfactor() const;

    void algorithm();

    void show(Ui::LearnWindow *ui);

    void changeScore(const int s);

    int getId() const;

private:
    /**
     * @brief
     * polish word
     */
    std::string plWord;

    /**
     * @brief
     * english word
     */
    std::string engWord;

    /**
     * @brief
     * quality response
     */
    int score;

    /**
     * @brief
     * last interval between repeats
     */
    int interval;

    /**
     * @brief
     * E-Factor
     */
    double efactor;
};

#endif // SIMPLEWORD_H
