/********************************************************************************
** Form generated from reading UI file 'DataBaseWords.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEWORDS_H
#define UI_DATABASEWORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataBaseWords
{
public:
    QWidget *scrollAreaWidgetContents;
    QPushButton *back_button;
    QPushButton *delete_button;
    QTableView *table_widget;

    void setupUi(QScrollArea *DataBaseWords)
    {
        if (DataBaseWords->objectName().isEmpty())
            DataBaseWords->setObjectName(QStringLiteral("DataBaseWords"));
        DataBaseWords->resize(528, 293);
        DataBaseWords->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        DataBaseWords->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        DataBaseWords->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        DataBaseWords->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 526, 291));
        back_button = new QPushButton(scrollAreaWidgetContents);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(410, 250, 91, 23));
        delete_button = new QPushButton(scrollAreaWidgetContents);
        delete_button->setObjectName(QStringLiteral("delete_button"));
        delete_button->setGeometry(QRect(300, 250, 101, 23));
        table_widget = new QTableView(scrollAreaWidgetContents);
        table_widget->setObjectName(QStringLiteral("table_widget"));
        table_widget->setGeometry(QRect(0, 0, 511, 251));
        DataBaseWords->setWidget(scrollAreaWidgetContents);

        retranslateUi(DataBaseWords);

        QMetaObject::connectSlotsByName(DataBaseWords);
    } // setupUi

    void retranslateUi(QScrollArea *DataBaseWords)
    {
        DataBaseWords->setWindowTitle(QApplication::translate("DataBaseWords", "ScrollArea", 0));
        back_button->setText(QApplication::translate("DataBaseWords", "Cofnij", 0));
        delete_button->setText(QApplication::translate("DataBaseWords", "Usu\305\204 zaznaczone", 0));
    } // retranslateUi

};

namespace Ui {
    class DataBaseWords: public Ui_DataBaseWords {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEWORDS_H
