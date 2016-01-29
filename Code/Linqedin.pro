#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T20:28:07
#
#-------------------------------------------------

QT       += core gui
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Linqedin
TEMPLATE = app


SOURCES += main.cpp\
    Grafica/accessoadmin.cpp \
    Grafica/accessoutente.cpp \
    Grafica/gestionecontatti.cpp \
    Grafica/gestioneprofilou.cpp \
    Grafica/mainwindow.cpp \
    Grafica/registrazione.cpp \
    Logica/utente.cpp \
    Logica/LinQedInAdmin.cpp \
    Logica/LinQedInClient.cpp \
    Logica/db.cpp \
    Grafica/modifica_tipologia_utente.cpp




HEADERS  += Grafica/accessoadmin.h \
    Grafica/accessoutente.h \
    Grafica/gestionecontatti.h \
    Grafica/gestioneprofilou.h \
    Grafica/mainwindow.h \
    Grafica/registrazione.h \
    Logica/utente.h \
    Logica/LinQedInAdmin.h \
    Logica/LinQedInClient.h \
    Logica/db.h \
    Grafica/modifica_tipologia_utente.h




FORMS    += Grafica/mainwindow.ui
