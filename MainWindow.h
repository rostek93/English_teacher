/**
 * @file MainWindow.h
 * @author Damian Pobrotyn , Kamil Rostecki
 * @brief Definition of the MainWindow Class.
 */

#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include "LearnWindow.h"
#include "CalendarWindow.h"
#include "AddWordWindow.h"
//#include <boost/intrusive_ptr.hpp>

namespace Ui {
class MainWindow;
}

/**
 * @brief
 * Class representing the GUI main window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionZamknij_triggered();
    void on_learn_button_clicked();
    void on_add_word_button_clicked();
    void on_number_words_slider_actionTriggered(int action);
    void on_number_words_slider_valueChanged(int value);
    void on_exit_button_clicked();
    void on_words_button_clicked();
    void on_schedule_button_clicked();

    void on_clear_button_clicked();

private:
    Ui::MainWindow *ui;
    QString str;

    /**
     * @brief
     * pointer on the Learn Window
     */
    QPointer<LearnWindow> lw;

    /**
     * @brief
     * pointer on the Add Word Window
     */
    QPointer<AddWordWindow> aww;

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

#endif // MainWindow_H
