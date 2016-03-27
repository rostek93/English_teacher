/**
 * @file AbstractWord.h
 * @author Kamil Rostecki and Damian Pobrotyn
 * @brief Definition of the class WordDecorator.
 */


#ifndef WORDDECORATOR_H
#define WORDDECORATOR_H

#include "AbstractWord.h"
#include <memory>

typedef std::shared_ptr<AbstractWord> PtrAbstWord;

/**
 * @brief
 * Abstract class, from which inherit all decorator classes.
 */
class WordDecorator: public AbstractWord
{
public:
    WordDecorator();

    /**
     * @brief
     * Constructor used to creating words with database
     * @param w decorated words
     */
    WordDecorator(PtrAbstWord w);

    /**
     * @brief
     * Constructor used to creating words with database
     * @param w decorated words
     * @param i is id word in the databse
     */
    WordDecorator(PtrAbstWord w, int i);

    virtual ~WordDecorator();

    std::string getEngWord() const;

    std::string getPlWord() const;

    virtual std::string getSentence() const = 0;

    virtual std::string getSynonyms() const = 0;

    int getInterval() const;

    double getEfactor() const;

    void algorithm();

    void show(Ui::LearnWindow *ui);

    void changeScore(const int s);

    int getId() const;

protected:
    /**
     * @brief
     * Decorated word.
     */
    PtrAbstWord dec;
};

#endif // WORDDECORATOR_H
