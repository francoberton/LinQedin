#ifndef MODIFICA_TIPOLOGIA_UTENTE_H
#define MODIFICA_TIPOLOGIA_UTENTE_H

#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHeaderView>
#include <string>
#include <QRadioButton>
#include <QMessageBox>
#include "../Logica/LinQedInAdmin.h"

class Modifica_Tipologia_Utente:public QWidget{
    Q_OBJECT
public:
    Modifica_Tipologia_Utente(LinQedInAdmin* l,string user,QWidget* =0);
    void gettipologiaUtente(const string &);
public slots:
    void modifica_tipo_utente();

private:
    QRadioButton* utente_basic;
    QRadioButton* utente_business;
    QRadioButton* utente_executive;
    std::string Tipo_Utente_init;
    std::string login;
    LinQedInAdmin *admin;
};

#endif // MODIFICA_TIPOLOGIA_UTENTE_H
