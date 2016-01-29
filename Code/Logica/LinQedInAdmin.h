#ifndef LINQEDINADMIN_H
#define LINQEDINADMIN_H
#include "db.h"
class LinQedInAdmin{
 private:
 DB* db;
 public:
 LinQedInAdmin();
 void insert(Utente*);
 Utente* find(const string &) const;
 void remove(const string &);
 // cambia tra Basic, Business, Executive
 void changeSubscriptionType(const string & ,string tipodiutente);
 void save() const;
 vector <Utente*> visualizza_utenti_registrati()const;
};

#endif // LINQEDINADMIN_H
