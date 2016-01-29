#ifndef GESTIONECONTATTI_H
#define GESTIONECONTATTI_H

#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QHeaderView>
#include <string>
#include "../Logica/LinQedInClient.h"

class GestioneContatti:public QWidget
{     Q_OBJECT
public:
    GestioneContatti(LinkedInClient*,QWidget* =0);
    void getuserautenticated(LinkedInClient*);
public slots:
    void add_contact();
    void remove_contact();
    void find();
    void visualizza_contacts();
    void save_DB();
private:
    LinkedInClient* client;
    QTableWidget* output;
    QLineEdit* LEcerca;
};


/*Parte Riguardante Utente Executive */
class Rete_Contatto : public QWidget
 {
     Q_OBJECT

 public:
     Rete_Contatto(LinkedInClient* c,string user,QWidget *parent = 0);
 public slots:
     void visualizza_rete_contatto();
 private:
     string contact;
     QTableWidget* rete_contatto;
     LinkedInClient* client;
 };

class Curriculum: public QWidget
{
    Q_OBJECT
public:
    Curriculum(LinkedInClient* c,string L_C,string F_S,string E_P,QWidget *parent = 0);
private:
    LinkedInClient* client;
};



#endif // GESTIONECONTATTI_H
