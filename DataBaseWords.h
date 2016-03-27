/**
 * @file AbstractWord.h
 * @author Kamil Rostecki and Damian Pobrotyn
 * @brief Definition of the class DataBaseWords.
 */


#ifndef DATABASEWORDS_H
#define DATABASEWORDS_H

#include <QScrollArea>
#include "DatabaseFile.h"

namespace Ui {
class DataBaseWords;
}

/**
 * @brief
 * Class representing the GUI window with database words, where user can see all words with database
 */
class DataBaseWords : public QScrollArea
{
    Q_OBJECT

public:
    explicit DataBaseWords(QWidget *parent = 0);

    ~DataBaseWords();

    /**
     * @brief
     * method refresh GUI after user delete words
     */
    void refresh();

private slots:
    void on_delete_button_clicked();
    void on_back_button_clicked();

private:
    Ui::DataBaseWords *ui;

    /**
     * @brief
     * object by which class have access to database.
     */
    DatabaseFile df;

    /**
     * @brief
     * name of database
     */
    std::string dBase;
};

#endif // DATABASEWORDS_H
