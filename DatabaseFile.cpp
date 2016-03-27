/**
 * @file LearnWindow.cpp
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Implementation of the DatabaseFile class methods.
 */

#include "DatabaseFile.h"
#include <QMessageBox>

using namespace std;

PtrAbstWord CreateSimpleWordFun(QSqlQuery &query) {
    int id = query.value(0).toInt();
    string plWord = query.value(1).toString().toStdString();
    string engWord = query.value(2).toString().toStdString();
    int interval = query.value(6).toInt();

    if (interval == 0)
        return PtrAbstWord(new SimpleWord(id, plWord, engWord));
    else {
        double efactor = query.value(7).toDouble();
        return PtrAbstWord(new SimpleWord(id, plWord, engWord, interval, efactor));
    }
}

PtrAbstWord CreateWordSentenceFun(QSqlQuery &query) {
    PtrAbstWord simple = WordFactory<AbstractWord>::getInstance().create(0,query);
    string sentence = query.value(4).toString().toStdString();
    return PtrAbstWord(new WordSentence(simple,sentence,simple->id));
}

PtrAbstWord CreateWordSynonymsFun(QSqlQuery &query) {
    PtrAbstWord simple = WordFactory<AbstractWord>::getInstance().create(0,query);
    string synonyms = query.value(3).toString().toStdString();
    return PtrAbstWord(new WordSynonyms(simple,synonyms,simple->id));
}

PtrAbstWord CreateWordSentenceSynonymsFun(QSqlQuery &query) {
    PtrAbstWord senten = WordFactory<AbstractWord>::getInstance().create(1,query);
    string synonyms = query.value(3).toString().toStdString();
    return PtrAbstWord(new WordSynonyms(senten,synonyms,senten->id));
}

DatabaseFile::DatabaseFile(){}

DatabaseFile::~DatabaseFile(){}

void DatabaseFile::loadWords(const string dBase, int new_words) {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName(QString::fromStdString(dBase));

    if(!db.open()){
        QMessageBox::critical(0,"Blad","Nie udalo się otworzyc bazy danych !");
    }
    else{
        try{
            QSqlQuery query;

            query.prepare( "select * FROM wordsList WHERE date <= CURRENT_DATE ORDER BY date");
            if(!query.exec()){
               throw exception();
            }
            while(query.next()) {
                int type = query.value(8).toInt();
                PtrAbstWord x = WordFactory<AbstractWord>::getInstance().create(type,query);
                vRepetition_words.push_back(x);
            }

            query.prepare( "select * from wordsList WHERE date IS NULL");
            if(!query.exec()){
               throw exception();
            }
            while(query.next() && (--new_words >= 0) ) {
                int type = query.value(8).toInt();
                PtrAbstWord y = WordFactory<AbstractWord>::getInstance().create(type,query);
                vNew_words.push_back(y);
            }

            if (vNew_words.size() == 0) {
                query.prepare( "select * from wordsList WHERE date > CURRENT_DATE");
                if(!query.exec()){
                   throw exception();
                }
                while(query.next() && (--new_words >= 0) ) {
                    int type = query.value(8).toInt();
                    PtrAbstWord y = WordFactory<AbstractWord>::getInstance().create(type,query);
                    vNew_words.push_back(y);
                }
            }

            db.close();
        }
        catch(const exception e){
            QMessageBox::critical(0,"Blad","Nie udalo się odczytac danych z bazy!");
        }
    }
}

void DatabaseFile::loadCalendar(const string dBase) {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName(QString::fromStdString(dBase));

    if(!db.open()){
        QMessageBox::critical(0,"Błąd","Nie udalo sie otworzyc bazy danych !");
    }
    else{
        try{
            QSqlQuery query;

            query.prepare("UPDATE wordslist SET date = CURRENT_DATE WHERE date IS NOT NULL and date < CURRENT_DATE");
            if(!query.exec()){
               throw exception();
            }

            query.prepare( "select date, COUNT(*) from wordsList where date IS NOT NULL GROUP BY date");
            if(!query.exec()){
               throw exception();
            }
            while(query.next()) {
                string date = query.value(0).toString().toStdString();
                int number = query.value(1).toInt();
                date_repetitions[date] = number;
            }

            db.close();
        }
        catch(const exception e){
            QMessageBox::critical(0,"Blad","Nie udalo się odczytac danych z bazy!");
        }
    }
}

void DatabaseFile::updateWords(const string dBase, PtrAbstWord word) {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName(QString::fromStdString(dBase));

    if(!db.open()){
        QMessageBox::critical(0,"Blad","Nie udalo się otworzyc bazy danych !");
    }
    else{
        try{
            QSqlQuery query;
            int id = word->getId();
            word->algorithm();
            int day = word->getInterval();

            QString str = "UPDATE wordslist SET date = date('now','+" + QString::number(day) +
                    " day'), interval=:interval, efactor=:efactor WHERE id=:id";
            query.prepare(str);
            query.bindValue(":id", QString::number(id));
            query.bindValue(":interval", QString::number(word->getInterval()));
            query.bindValue(":efactor", QString::number(word->getEfactor()));

            if(!query.exec()){
                throw exception();
            }

            db.close();
        }
        catch(const exception e){
            QMessageBox::critical(0,"Blad","Nie udalo sie odczytac danych z bazy catch!");
        }
    }
}

void DatabaseFile::addWord(const string dBase, int type, QString pol, QString eng, QString sentence, QString synonyms) {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName(QString::fromStdString(dBase));

    if(!db.open()){
        QMessageBox::critical(0,"Blad","Nie udalo się otworzyc bazy danych !");
    }
    else{
        try{
            QSqlQuery query;

            query.prepare("SELECT * FROM wordsList");
            if(!query.exec()){
               throw exception();
            }
            query.last();
            int size = query.value(0).toInt()+1;

            if (type == 0)
                query.prepare("INSERT INTO wordsList (id, pl, eng, type) VALUES ( :id, :pl, :eng, :type) ");
            else if (type == 1)
                query.prepare("INSERT INTO wordsList (id, pl, eng, sentence, type) VALUES (:id, :pl, :eng, :sentence, :type) ");
            else if (type == 2)
                query.prepare("INSERT INTO wordsList (id, pl, eng, synonym, type) VALUES (:id, :pl, :eng, :synonyms, :type) ");
            else if (type == 3)
                query.prepare("INSERT INTO wordsList (id, pl, eng, sentence, synonym, type) VALUES (:id, :pl, :eng, :sentence, :synonyms, :type) ");

            query.bindValue(":id", QString::number(size));
            query.bindValue(":pl", pol);
            query.bindValue(":eng", eng);
            query.bindValue(":type", QString::number(type));
            query.bindValue(":sentence", sentence);
            query.bindValue(":synonyms", synonyms);

            if(!query.exec()){
                throw exception();
            }

            db.close();
        }
        catch(const exception e){
            QMessageBox::critical(0,"Blad","Nie udalo się odczytac danych z bazy catch!");
        }
    }
}

void DatabaseFile::loadAllWords(const string dBase) {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName(QString::fromStdString(dBase));

    if(!db.open()){
        QMessageBox::critical(0,"Blad","Nie udalo się otworzyc bazy danych !");
    }
    else{
        try{
            QSqlQuery query;
            query.prepare( "select * FROM wordsList");
            if(!query.exec()){
               throw exception();
            }
            while(query.next()) {
                int type = query.value(8).toInt();
                PtrAbstWord x = WordFactory<AbstractWord>::getInstance().create(type,query);
                vAll_words.push_back(x);
            }

            db.close();
        }
        catch(const exception e){
            QMessageBox::critical(0,"Blad","Nie udalo się odczytac danych z bazy catch!");
        }
    }
}

void DatabaseFile::removeWord(const std::string dBase, int id) {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName(QString::fromStdString(dBase));

    if(!db.open()){
        QMessageBox::critical(0,"Blad","Nie udalo się otworzyc bazy danych !");
    }
    else{
        try{
            QSqlQuery query;
            query.prepare("DELETE FROM wordslist WHERE id=:id");
            query.bindValue(":id", QString::number(id));

            if(!query.exec()){
                throw exception();
            }

            db.close();
        }
        catch(const exception e){
            QMessageBox::critical(0,"Blad","Nie udalo sie odczytac danych z bazy catch!");
        }
    }
}

void DatabaseFile::resetUser(const string dBase) {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName(QString::fromStdString(dBase));

    if(!db.open()){
        QMessageBox::critical(0,"Blad","Nie udalo się otworzyc bazy danych !");
    }
    else{
        try{
            QSqlQuery query;
            QString str = "UPDATE wordslist SET date = NULL, interval=0, efactor=NULL";
            query.prepare(str);

            if(!query.exec()){
                throw exception();
            }

            db.close();
        }
        catch(const exception e){
            QMessageBox::critical(0,"Blad","Nie udalo sie odczytac danych z bazy catch!");
        }
    }
}


void DatabaseFile::registerFun() {
    WordFactory<AbstractWord>::getInstance().regist(0,CreateSimpleWordFun);
    WordFactory<AbstractWord>::getInstance().regist(1,CreateWordSentenceFun);
    WordFactory<AbstractWord>::getInstance().regist(2,CreateWordSynonymsFun);
    WordFactory<AbstractWord>::getInstance().regist(3,CreateWordSentenceSynonymsFun);
}
