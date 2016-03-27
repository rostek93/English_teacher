/**
 * @file AbstractWord.h
 * @author Kamil Rostecki and Damian Pobrotyn
 * @brief Definition of the class WordSynonyms.
 */

#ifndef WORDSYNONYMS_H
#define WORDSYNONYMS_H

#include "WordDecorator.h"

/**
 * @brief
 * Class adding to SimpleWord synonyms
 */
class WordSynonyms: public WordDecorator
{
public:
    WordSynonyms();

    /**
     * @brief
     * Constructor creating new words with synonyms.
     * @param dec decorated words
     * @param synonyms - synonyms
     * @param id is id word in the databse
     */
    WordSynonyms(PtrAbstWord dec, std::string synonyms, int id);

    ~WordSynonyms();

    std::string getSentence() const;

    std::string getSynonyms() const;

    void show(Ui::LearnWindow *ui);

private:
    /**
     * @brief
     * synonyms
     */
    std::string synonyms;
};

#endif // WORDSYNONYMS_H
