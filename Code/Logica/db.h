#ifndef DB_H
#define DB_H
#include <QXmlStreamWriter>
#include <QFile>
#include <QSettings>
#include <QDomDocument>
#include <QVector>
#include <QDebug>
#include "utente.h"


class DB {
    friend class UtenteBasic;
    friend class UtenteBusiness;
    friend class UtenteExecutive;
 public:
 void load(); // carica da file
 void save() const;  // salva su file
 // cerca l'utente (con il suo tipo)
 // avente Username u nel DB,
 Utente* find(const string &);
 void modifica_profilo(Utente* ,Utente*);
 void insert(Utente *u);
 void remove(const string& user);
 Utente* autentication(Username);
 void changeSubscriptionType(const string& ,string tipodiutente);
 vector<Utente*> visualizza_utenti_registrati() const;
 private:
 vector <Utente*> db;
};


#endif // DB_H
