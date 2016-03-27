/**
 * @file main.cpp
 * @author Damian Pobrotyn , Kamil Rostecki
 * @brief Function main.
 */

#include "MainWindow.h"
#include "DatabaseFile.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    DatabaseFile df;
    df.registerFun();

    return a.exec();
}

