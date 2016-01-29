#ifndef GESTIONEPROFILOU_H
#define GESTIONEPROFILOU_H

#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QHeaderView>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QFont>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSize>
#include <QMessageBox>
#include "mainwindow.h"
#include "modifica_profilo.h"
#include "../Logica/LinQedInClient.h"

class GestioneProfiloU:public QWidget
{   Q_OBJECT
public:
    GestioneProfiloU(LinkedInClient*, QWidget* =0);

public slots:
    void visualizzaprofilo();
    void showpassword();
    void modifica_dati();
    void savedb();
private:
    LinkedInClient* client;
    QTableWidget* output;
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
};

#endif // GESTIONEPROFILOU_H
