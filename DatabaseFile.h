/**
 * @file AbstractWord.h
 * @author Kamil Rostecki and Damian Pobrotyn
 * @brief Definition of the class DatabaseFile.
 */


#ifndef DATABASEFILE_H
#define DATABASEFILE_H

#include "SimpleWord.h"
#include "WordSentence.h"
#include "WordSynonyms.h"
#include "WordFactory.hpp"
#include <vector>

/**
 * @brief
 * class used to write and read date with database
 */
class DatabaseFile
{
public:
    DatabaseFile();

    ~DatabaseFile();

    /**
     * @brief
     * Load words to repeat to vector name - vRepeatition_words and new words to learn to vector name - vNew_words
     * @param dBase is name of databse
     * @param new_words is number of new words to learn
     */
    void loadWords(const std::string dBase, int new_words);

    /**
     * @brief
     * Load all words with database to vector name - vAll_words
     * @param dBase is name of database
     */
    void loadAllWords(const std::string dBase);

    /**
     * @brief
     * Load dates and the number of repetitions to map nampe date_repetitions
     * @param dBase is name of database
     */
    void loadCalendar(const std::string dBase);

    /**
     * @brief
     * Set new date for repeat
     * @param dBase is name of database
     * @param word is pointer to word, which is update
     */
    void updateWords(const std::string dBase, PtrAbstWord word);

    /**
     * @brief
     * Register pointers to all functions creating particular type of words in the Factory.
     */
    void registerFun();

    /**
     * @brief
     * Add new word to database
     * @param dBase is name of database
     * @param type is type of word
     * @param pol is polish word
     * @param eng is english word
     * @param sentence is sentence with this english word
     * @param synonyms are synonyms this word
     */
    void addWord(const std::string dBase, int type, QString pol, QString eng, QString sentence, QString synonyms);

    /**
     * @brief
     * Remove selected word with database
     * @param dBase is name of database
     * @param id is id word that is removed
     */
    void removeWord(const std::string dBase, int id);

    /**
     * @brief
     * Reset User's progress.
     * @param dBase is name of database
     */
    void resetUser(const std::string dBase);
    /**
     * @brief
     * Vector contains words to repeat
     */
    std::vector<PtrAbstWord> vRepetition_words;

    /**
     * @brief
     * Vector contains new words to learn
     */
    std::vector<PtrAbstWord> vNew_words;

    /**
     * @brief
     * Vecotr contains all words with database
     */
    std::vector<PtrAbstWord> vAll_words;

    /**
     * @brief
     * map contains dates and the number of repetitions
     */
    std::map<std::string,int> date_repetitions;
};

PtrAbstWord CreateSimpleWordFun(QSqlQuery &query);
PtrAbstWord CreateWordSentenceFun(QSqlQuery &query);
PtrAbstWord CreateWordSynonymsFun(QSqlQuery &query);
PtrAbstWord CreateWordSentenceSynonymsFun(QSqlQuery &query);


#endif // DATABASEFILE_H
