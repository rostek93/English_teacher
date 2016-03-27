/********************************************************************************
** Form generated from reading UI file 'CalendarWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARWINDOW_H
#define UI_CALENDARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalendarWindow
{
public:
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QCalendarWidget *calendar_widget;
    QPushButton *back_button;
    QTableView *table_view;

    void setupUi(QScrollArea *CalendarWindow)
    {
        if (CalendarWindow->objectName().isEmpty())
            CalendarWindow->setObjectName(QStringLiteral("CalendarWindow"));
        CalendarWindow->resize(528, 293);
        CalendarWindow->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 526, 291));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 0, 101, 31));
        calendar_widget = new QCalendarWidget(scrollAreaWidgetContents);
        calendar_widget->setObjectName(QStringLiteral("calendar_widget"));
        calendar_widget->setGeometry(QRect(250, 30, 271, 211));
        back_button = new QPushButton(scrollAreaWidgetContents);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(380, 250, 75, 23));
        table_view = new QTableView(scrollAreaWidgetContents);
        table_view->setObjectName(QStringLiteral("table_view"));
        table_view->setGeometry(QRect(0, 31, 241, 211));
        CalendarWindow->setWidget(scrollAreaWidgetContents);

        retranslateUi(CalendarWindow);

        QMetaObject::connectSlotsByName(CalendarWindow);
    } // setupUi

    void retranslateUi(QScrollArea *CalendarWindow)
    {
        CalendarWindow->setWindowTitle(QApplication::translate("CalendarWindow", "ScrollArea", 0));
        label->setText(QApplication::translate("CalendarWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600; text-decoration: underline; color:#ff0000;\">Kalendarz</span></p></body></html>", 0));
        back_button->setText(QApplication::translate("CalendarWindow", "Cofnij", 0));
    } // retranslateUi

};

namespace Ui {
    class CalendarWindow: public Ui_CalendarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARWINDOW_H
