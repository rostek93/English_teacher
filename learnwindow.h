/**
 * @file LearnWindow.h
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Definition of the class LearnWindow.
 */

#ifndef LearnWindow_H
#define LearnWindow_H

#include <QDialog>
#include "string"
#include "QtSql/QtSql"
#include <time.h>
#include <vector>
#include "AbstractWord.h"
#include "DatabaseFile.h"


namespace Ui {
class LearnWindow;
}

/**
 * @brief
 * Class representing the GUI learn window. User can repeat and learn new words.
 */
class LearnWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LearnWindow(QWidget *parent = 0, int number=0);

    ~LearnWindow();

    /**
     * @brief
     * display next word
     */
    void getWords();

private slots:
    void on_check_button_clicked();
    void on_correctly_button_clicked();
    void on_incorrectly_button_clicked();
    void on_almost_button_clicked();


private:
    Ui::LearnWindow *ui;

    /**
     * @brief
     * number of learned words today is display in Learn Window
     */
    int learned_words_counter;

    /**
     * @brief
     * number of repeat words today is display in Learn Window
     */
    int repeated_words_counter;

    /**
     * @brief
     * number of selected words to learn today
     */
    int words_to_learn;

    /**
     * @brief
     * number of words to repeat today
     */
    int words_to_repeat;

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

#endif // LearnWindow_H
