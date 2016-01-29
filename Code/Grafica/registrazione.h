#ifndef REGISTRAZIONE_H
#define REGISTRAZIONE_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QMessageBox>
#include <QRadioButton>
#include "../Logica/LinQedInAdmin.h"
#include<string>
#include <QDateEdit>
using std::string;


class Registrazione:public QWidget
{    Q_OBJECT
public:
    Registrazione(LinQedInAdmin*, QWidget* = 0);
    string gettipoutente();

public slots:
     void Registra();
     void ShowPassword();
private:
      QLineEdit* cnome;
      QLineEdit* ccognome;
      QDateEdit* cdatadinascita;
      QLineEdit* cluogodinascita;
      QTextEdit* clingue_conosciute;
      QTextEdit* cformazione_scolastica;
      QTextEdit* cesperienze_professionali;
      QLineEdit* cusername;
      QLineEdit* cpassword;
      QCheckBox* show_password;
      LinQedInAdmin* admin;
      QRadioButton* utente_basic;
      QRadioButton* utente_business;
      QRadioButton* utente_executive;
};

#endif // REGISTRAZIONE_H
