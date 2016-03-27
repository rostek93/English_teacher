/********************************************************************************
** Form generated from reading UI file 'LearnWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNWINDOW_H
#define UI_LEARNWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LearnWindow
{
public:
    QPushButton *check_button;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *buttonsLayout;
    QPushButton *incorrectly_button;
    QPushButton *almost_button;
    QPushButton *correctly_button;
    QLabel *learnedWordsLabel;
    QLCDNumber *lcd_new_number;
    QLabel *new_words_label;
    QLabel *synonym_label;
    QLabel *eng_word_label;
    QLabel *synonym_label_2;
    QLabel *pl_word_label;
    QLabel *sentence_label_2;
    QLabel *engWordLabel_2;
    QLabel *sentence_label;
    QLabel *plwordlabel;
    QLabel *repeat_words_label;
    QLabel *repeated_words_label;
    QLCDNumber *lcd_repeat_number;

    void setupUi(QDialog *LearnWindow)
    {
        if (LearnWindow->objectName().isEmpty())
            LearnWindow->setObjectName(QStringLiteral("LearnWindow"));
        LearnWindow->resize(407, 303);
        LearnWindow->setMinimumSize(QSize(407, 303));
        LearnWindow->setMaximumSize(QSize(407, 303));
        check_button = new QPushButton(LearnWindow);
        check_button->setObjectName(QStringLiteral("check_button"));
        check_button->setGeometry(QRect(290, 270, 101, 23));
        horizontalLayoutWidget = new QWidget(LearnWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 210, 320, 61));
        buttonsLayout = new QHBoxLayout(horizontalLayoutWidget);
        buttonsLayout->setObjectName(QStringLiteral("buttonsLayout"));
        buttonsLayout->setContentsMargins(0, 0, 0, 0);
        incorrectly_button = new QPushButton(horizontalLayoutWidget);
        incorrectly_button->setObjectName(QStringLiteral("incorrectly_button"));

        buttonsLayout->addWidget(incorrectly_button);

        almost_button = new QPushButton(horizontalLayoutWidget);
        almost_button->setObjectName(QStringLiteral("almost_button"));

        buttonsLayout->addWidget(almost_button);

        correctly_button = new QPushButton(horizontalLayoutWidget);
        correctly_button->setObjectName(QStringLiteral("correctly_button"));

        buttonsLayout->addWidget(correctly_button);

        learnedWordsLabel = new QLabel(LearnWindow);
        learnedWordsLabel->setObjectName(QStringLiteral("learnedWordsLabel"));
        learnedWordsLabel->setGeometry(QRect(140, 40, 81, 21));
        lcd_new_number = new QLCDNumber(LearnWindow);
        lcd_new_number->setObjectName(QStringLiteral("lcd_new_number"));
        lcd_new_number->setGeometry(QRect(230, 43, 51, 20));
        new_words_label = new QLabel(LearnWindow);
        new_words_label->setObjectName(QStringLiteral("new_words_label"));
        new_words_label->setGeometry(QRect(10, 40, 121, 21));
        synonym_label = new QLabel(LearnWindow);
        synonym_label->setObjectName(QStringLiteral("synonym_label"));
        synonym_label->setGeometry(QRect(200, 110, 169, 32));
        eng_word_label = new QLabel(LearnWindow);
        eng_word_label->setObjectName(QStringLiteral("eng_word_label"));
        eng_word_label->setGeometry(QRect(200, 140, 169, 33));
        synonym_label_2 = new QLabel(LearnWindow);
        synonym_label_2->setObjectName(QStringLiteral("synonym_label_2"));
        synonym_label_2->setGeometry(QRect(90, 110, 89, 32));
        pl_word_label = new QLabel(LearnWindow);
        pl_word_label->setObjectName(QStringLiteral("pl_word_label"));
        pl_word_label->setGeometry(QRect(200, 80, 169, 33));
        sentence_label_2 = new QLabel(LearnWindow);
        sentence_label_2->setObjectName(QStringLiteral("sentence_label_2"));
        sentence_label_2->setGeometry(QRect(90, 170, 89, 33));
        engWordLabel_2 = new QLabel(LearnWindow);
        engWordLabel_2->setObjectName(QStringLiteral("engWordLabel_2"));
        engWordLabel_2->setGeometry(QRect(90, 140, 89, 33));
        sentence_label = new QLabel(LearnWindow);
        sentence_label->setObjectName(QStringLiteral("sentence_label"));
        sentence_label->setGeometry(QRect(200, 170, 191, 33));
        plwordlabel = new QLabel(LearnWindow);
        plwordlabel->setObjectName(QStringLiteral("plwordlabel"));
        plwordlabel->setGeometry(QRect(90, 80, 89, 33));
        repeat_words_label = new QLabel(LearnWindow);
        repeat_words_label->setObjectName(QStringLiteral("repeat_words_label"));
        repeat_words_label->setGeometry(QRect(10, 20, 121, 16));
        repeated_words_label = new QLabel(LearnWindow);
        repeated_words_label->setObjectName(QStringLiteral("repeated_words_label"));
        repeated_words_label->setGeometry(QRect(140, 20, 91, 16));
        lcd_repeat_number = new QLCDNumber(LearnWindow);
        lcd_repeat_number->setObjectName(QStringLiteral("lcd_repeat_number"));
        lcd_repeat_number->setGeometry(QRect(230, 20, 51, 20));

        retranslateUi(LearnWindow);

        QMetaObject::connectSlotsByName(LearnWindow);
    } // setupUi

    void retranslateUi(QDialog *LearnWindow)
    {
        LearnWindow->setWindowTitle(QApplication::translate("LearnWindow", "Nauka s\305\202\303\263wek", 0));
        check_button->setText(QApplication::translate("LearnWindow", "Sprawd\305\272", 0));
        incorrectly_button->setText(QApplication::translate("LearnWindow", "Nie wiem", 0));
        almost_button->setText(QApplication::translate("LearnWindow", "Prawie", 0));
        correctly_button->setText(QApplication::translate("LearnWindow", "Wiem", 0));
        learnedWordsLabel->setText(QApplication::translate("LearnWindow", "Nauczone s\305\202owa", 0));
        new_words_label->setText(QApplication::translate("LearnWindow", "Nowe s\305\202owa na dzi\305\233: ", 0));
        synonym_label->setText(QApplication::translate("LearnWindow", "Synonimy:", 0));
        eng_word_label->setText(QApplication::translate("LearnWindow", "Angielskie s\305\202owo", 0));
        synonym_label_2->setText(QApplication::translate("LearnWindow", "Synonimy           :", 0));
        pl_word_label->setText(QApplication::translate("LearnWindow", "Polskie s\305\202owo", 0));
        sentence_label_2->setText(QApplication::translate("LearnWindow", "Zdanie               :", 0));
        engWordLabel_2->setText(QApplication::translate("LearnWindow", "Angielskie s\305\202owo:", 0));
        sentence_label->setText(QApplication::translate("LearnWindow", "Zdanie               :", 0));
        plwordlabel->setText(QApplication::translate("LearnWindow", "Polskie s\305\202owo     :", 0));
        repeat_words_label->setText(QApplication::translate("LearnWindow", "S\305\202owa do powt\303\263rki:", 0));
        repeated_words_label->setText(QApplication::translate("LearnWindow", "Powt\303\263rzone s\305\202owa", 0));
    } // retranslateUi

};

namespace Ui {
    class LearnWindow: public Ui_LearnWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNWINDOW_H
