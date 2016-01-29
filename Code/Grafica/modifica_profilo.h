#ifndef MODIFICA_PROFILO_H
#define MODIFICA_PROFILO_H

#include<QTextEdit>
#include <QLineEdit>
#include<QRadioButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QErrorMessage>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include "Logica/LinQedInClient.h"

class Modifica_Profilo:public QWidget
{    Q_OBJECT
  public:
    Modifica_Profilo(LinkedInClient*, QWidget* = 0);
  public slots:
    void modifica_dati();
    void compilacaselle();
    void showpassword();
  private:
      QLineEdit* cnome;
      QLineEdit* ccognome;
      QLineEdit* cdatadinascita;
      QLineEdit* cluogodinascita;
      QTextEdit* clingue_conosciute;
      QTextEdit* cformazione_scolastica;
      QTextEdit* cesperienze_professionali;
      QLineEdit* cusername;
      QLineEdit* cpassword;
      QCheckBox* show_password;
      LinkedInClient* client;
      QRadioButton* utente_basic;
      QRadioButton* utente_business;
      QRadioButton* utente_executive;
};

#endif // MODIFICA_PROFILO_H
