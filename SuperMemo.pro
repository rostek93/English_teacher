
QT       += core gui
QT      += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuperMemo
TEMPLATE = app


SOURCES +=\
    AddWordWindow.cpp \
    LearnWindow.cpp \
    MainWindow.cpp \
    AbstractWord.cpp \
    WordDecorator.cpp \
    SimpleWord.cpp \
    WordSentence.cpp \
    WordSynonyms.cpp \
    DatabaseFile.cpp \
    main.cpp \
    DataBaseWords.cpp \
    CalendarWindow.cpp

HEADERS  += \
    AddWordWindow.h \
    LearnWindow.h \
    MainWindow.h \
    AbstractWord.h \
    WordDecorator.h \
    SimpleWord.h \
    WordSentence.h \
    WordSynonyms.h \
    DatabaseFile.h \
    DataBaseWords.h \
    CalendarWindow.h \
    WordFactory.hpp

FORMS    += \
    AddWordWindow.ui \
    LearnWindow.ui \
    MainWindow.ui \
    DataBaseWords.ui \
    CalendarWindow.ui
