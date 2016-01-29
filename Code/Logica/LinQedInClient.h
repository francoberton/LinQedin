#ifndef LINQEDINCLIENT_H
#define LINQEDINCLIENT_H
#include "db.h"
class LinkedInClient {
 public:
 Utente* u;
 DB *db; // inizializzato da file,
 // usato in sola lettura
 LinkedInClient(Username un) {
 db=new DB();
 // carica il DB
 db->load();
 // cerca l'utente client con Username s
 u = db->autentication(un);
 }

 void aggiornaProfilo(Utente*);
 void savedb();
 Utente* find(const string & user)const;
 bool insertRete(const string &);
 bool removeRete(const string &);

 // funzionalita` di ricerca autorizzata per u!
 vector <string> ricerca(const string &);
};

#endif // LINQEDINCLIENT_H
