/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionZamknij;
    QAction *actionZmien_uzytkownika;
    QWidget *centralWidget;
    QSlider *number_words_slider;
    QLabel *label_2;
    QLabel *number_words_label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *learn_button;
    QPushButton *schedule_button;
    QPushButton *add_word_button;
    QPushButton *words_button;
    QPushButton *clear_button;
    QPushButton *exit_button;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(520, 283);
        MainWindow->setMinimumSize(QSize(520, 283));
        MainWindow->setMaximumSize(QSize(520, 283));
        MainWindow->setWindowTitle(QStringLiteral("Program do nauki"));
        MainWindow->setAutoFillBackground(false);
        actionZamknij = new QAction(MainWindow);
        actionZamknij->setObjectName(QStringLiteral("actionZamknij"));
        actionZmien_uzytkownika = new QAction(MainWindow);
        actionZmien_uzytkownika->setObjectName(QStringLiteral("actionZmien_uzytkownika"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        number_words_slider = new QSlider(centralWidget);
        number_words_slider->setObjectName(QStringLiteral("number_words_slider"));
        number_words_slider->setGeometry(QRect(310, 80, 160, 19));
        number_words_slider->setMouseTracking(false);
        number_words_slider->setAcceptDrops(false);
        number_words_slider->setMinimum(1);
        number_words_slider->setMaximum(50);
        number_words_slider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 60, 151, 21));
        number_words_label = new QLabel(centralWidget);
        number_words_label->setObjectName(QStringLiteral("number_words_label"));
        number_words_label->setGeometry(QRect(380, 100, 47, 13));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(170, 20, 131, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        learn_button = new QPushButton(verticalLayoutWidget);
        learn_button->setObjectName(QStringLiteral("learn_button"));

        verticalLayout->addWidget(learn_button);

        schedule_button = new QPushButton(verticalLayoutWidget);
        schedule_button->setObjectName(QStringLiteral("schedule_button"));
        schedule_button->setEnabled(true);

        verticalLayout->addWidget(schedule_button);

        add_word_button = new QPushButton(verticalLayoutWidget);
        add_word_button->setObjectName(QStringLiteral("add_word_button"));

        verticalLayout->addWidget(add_word_button);

        words_button = new QPushButton(verticalLayoutWidget);
        words_button->setObjectName(QStringLiteral("words_button"));

        verticalLayout->addWidget(words_button);

        clear_button = new QPushButton(verticalLayoutWidget);
        clear_button->setObjectName(QStringLiteral("clear_button"));

        verticalLayout->addWidget(clear_button);

        exit_button = new QPushButton(verticalLayoutWidget);
        exit_button->setObjectName(QStringLiteral("exit_button"));

        verticalLayout->addWidget(exit_button);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 520, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(actionZamknij);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionZamknij->setText(QApplication::translate("MainWindow", "Zamknij", 0));
        actionZmien_uzytkownika->setText(QApplication::translate("MainWindow", "Zmien uzytkownika", 0));
        label_2->setText(QApplication::translate("MainWindow", "Ile s\305\202\303\263wek chcesz si\304\231 uczy\304\207?", 0));
        number_words_label->setText(QApplication::translate("MainWindow", "1", 0));
        learn_button->setText(QApplication::translate("MainWindow", "Nauka", 0));
        schedule_button->setText(QApplication::translate("MainWindow", "Kalendarz", 0));
        add_word_button->setText(QApplication::translate("MainWindow", "Dodaj s\305\202owo", 0));
        words_button->setText(QApplication::translate("MainWindow", "Baza s\305\202\303\263w", 0));
        clear_button->setText(QApplication::translate("MainWindow", "Zresetuj", 0));
        exit_button->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
