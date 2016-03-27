/**
 * @file AbstractWord.h
 * @author Kamil Rostecki and Damian Pobrotyn
 * @brief Definition and implementation of the class Factory.
 */

#ifndef WORDFACTORY_H
#define WORDFACTORY_H

#include <memory>
#include <map>
#include "QtSql/QtSql"

/**
 * @brief
 * Class representing Factory.
 */
template<typename Word>
class WordFactory
{
public:

    typedef std::shared_ptr<Word> PtrWord;
    typedef PtrWord (*CreateWordFun)(QSqlQuery &query);


    /**
     * @brief
     * Enables an access to the class.
     */
    static WordFactory<Word>& getInstance(){
        static WordFactory instance;
        return instance;
    }

    /**
     * @brief
     * Registers all possible types in the factory.
     * @param type is type of created word
     * @param fun pointer to the function creating particular type of words
     */
    void regist(int type,CreateWordFun fun){
        callbacks_.insert(std::pair<int,CreateWordFun>(type,fun));
    }

    /**
     * @brief
     * Creates an object of a particular type.
     * @param id type of created word
     * @param query object representing query  in sql
     */
    PtrWord create(int type, QSqlQuery query){
        Callbacks::const_iterator it = callbacks_.find(type);
        if(it == callbacks_.end()){
             throw exception();  // Blad, nieznany typ figury
        }
        else{
            return it->second(query);
        }
    }

private:
    WordFactory() {}
    WordFactory(const WordFactory&) {}
    WordFactory& operator=(const WordFactory&) {}

    typedef std::map<int,CreateWordFun> Callbacks;

    /**
     * @brief
     * map contains id and pointer on the function creating particular type of words.
     */
    Callbacks callbacks_;

};

#endif // WORDFACTORY_H
