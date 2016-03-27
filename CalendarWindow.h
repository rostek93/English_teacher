/**
 * @file AbstractWord.h
 * @author Kamil Rostecki and Damian Pobrotyn
 * @brief Definition of the class CalendarWindow.
 */

#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QScrollArea>
#include "DatabaseFile.h"

namespace Ui {
class CalendarWindow;
}

/**
 * @brief
 * Class representing the GUI window with calendar, where user can see repetitions date.
 */
class CalendarWindow : public QScrollArea
{
    Q_OBJECT

public:
    explicit CalendarWindow(QWidget *parent = 0);

    ~CalendarWindow();

private slots:
    void on_back_button_clicked();

private:
    Ui::CalendarWindow *ui;

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

#endif // CALENDARWINDOW_H
