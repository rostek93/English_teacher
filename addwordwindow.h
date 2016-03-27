/**
 * @file AddWordWindow.h
 * @author Damian Pobrotyn and Kamil Rostecki
 * @brief Definition of the class AddWordWindow.
 */

#ifndef AddWordWindow_H
#define AddWordWindow_H

#include <QDialog>
#include "DatabaseFile.h"

namespace Ui {
class AddWordWindow;
}

/**
 * @brief
 * Class representing the GUI window adding words. User can add a new word to the database.
 */
class AddWordWindow : public QDialog
{
    Q_OBJECT

public:

    explicit AddWordWindow(QWidget *parent = 0);

    ~AddWordWindow();

private slots:
    void on_cancel_button_clicked();
    void on_save_button_clicked();


private:
    Ui::AddWordWindow *ui;

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

#endif // AddWordWindow_H
