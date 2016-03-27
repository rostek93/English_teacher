/********************************************************************************
** Form generated from reading UI file 'AddWordWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWORDWINDOW_H
#define UI_ADDWORDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWordWindow
{
public:
    QLabel *label;
    QLineEdit *eng_word_edit;
    QLabel *label_2;
    QLineEdit *pol_word_edit;
    QLabel *label_3;
    QLineEdit *sentence_edit;
    QLabel *label_4;
    QLineEdit *synonyms_edit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancel_button;
    QPushButton *save_button;

    void setupUi(QDialog *AddWordWindow)
    {
        if (AddWordWindow->objectName().isEmpty())
            AddWordWindow->setObjectName(QStringLiteral("AddWordWindow"));
        AddWordWindow->resize(400, 300);
        label = new QLabel(AddWordWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 23, 47, 20));
        eng_word_edit = new QLineEdit(AddWordWindow);
        eng_word_edit->setObjectName(QStringLiteral("eng_word_edit"));
        eng_word_edit->setGeometry(QRect(40, 40, 141, 21));
        label_2 = new QLabel(AddWordWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(40, 70, 91, 16));
        pol_word_edit = new QLineEdit(AddWordWindow);
        pol_word_edit->setObjectName(QStringLiteral("pol_word_edit"));
        pol_word_edit->setGeometry(QRect(40, 90, 141, 21));
        label_3 = new QLabel(AddWordWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(40, 120, 111, 16));
        sentence_edit = new QLineEdit(AddWordWindow);
        sentence_edit->setObjectName(QStringLiteral("sentence_edit"));
        sentence_edit->setGeometry(QRect(40, 140, 141, 20));
        label_4 = new QLabel(AddWordWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(40, 170, 111, 16));
        synonyms_edit = new QLineEdit(AddWordWindow);
        synonyms_edit->setObjectName(QStringLiteral("synonyms_edit"));
        synonyms_edit->setGeometry(QRect(40, 190, 141, 20));
        horizontalLayoutWidget = new QWidget(AddWordWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(190, 240, 191, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancel_button = new QPushButton(horizontalLayoutWidget);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));

        horizontalLayout->addWidget(cancel_button);

        save_button = new QPushButton(horizontalLayoutWidget);
        save_button->setObjectName(QStringLiteral("save_button"));

        horizontalLayout->addWidget(save_button);


        retranslateUi(AddWordWindow);

        QMetaObject::connectSlotsByName(AddWordWindow);
    } // setupUi

    void retranslateUi(QDialog *AddWordWindow)
    {
        AddWordWindow->setWindowTitle(QApplication::translate("AddWordWindow", "Dodaj s\305\202owo", 0));
        label->setText(QApplication::translate("AddWordWindow", "S\305\202\303\263wko", 0));
        label_2->setText(QApplication::translate("AddWordWindow", "Polskie znaczenie", 0));
        label_3->setText(QApplication::translate("AddWordWindow", "Przyk\305\202adowe zdanie", 0));
        label_4->setText(QApplication::translate("AddWordWindow", "Synonimy", 0));
        cancel_button->setText(QApplication::translate("AddWordWindow", "Anuluj", 0));
        save_button->setText(QApplication::translate("AddWordWindow", "Zapisz", 0));
    } // retranslateUi

};

namespace Ui {
    class AddWordWindow: public Ui_AddWordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWORDWINDOW_H
