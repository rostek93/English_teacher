/**
 * @file AbstractWord.h
 * @author Kamil Rostecki and Damian Pobrotyn
 * @brief Definition of the class WordSentence.
 */

#ifndef WORDSENTENCE_H
#define WORDSENTENCE_H

#include "WordDecorator.h"

/**
 * @brief
 * Class adding to SimpleWord sentence
 */
class WordSentence: public WordDecorator
{
public:
    WordSentence();

    /**
     * @brief
     * Constructor creating new words with sentence.
     * @param dec decorated words
     * @param sentence - sentence
     * @param id is id word in the databse
     */
    WordSentence(PtrAbstWord dec, std::string sentence, int id);

    ~WordSentence();

    std::string getSentence() const;

    std::string getSynonyms() const;

    void show(Ui::LearnWindow *ui);

private:
    /**
     * @brief
     * sentence
     */
    std::string sentence;
};

#endif // WORDSENTENCE_H
