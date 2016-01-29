#ifndef ACCESSOADMIN_H
#define ACCESSOADMIN_H
#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QSize>
#include <QHeaderView>
#include <QMessageBox>
#include "registrazione.h"
#include "modifica_tipologia_utente.h"
#include "mainwindow.h"

class AccessoAdmin:public QWidget
{
    Q_OBJECT
public:
    AccessoAdmin(LinQedInAdmin* a, QWidget* =0);
public slots:
    void find();
    void remove_utente();
    void visualizza_utenti_registrati();
    void modifica_tipologia_utente();
    void savedb();

private:
   QLineEdit* cercautente;
   QTableWidget* output;
   LinQedInAdmin* admin;
};

#endif // ACCESSOADMIN_H
