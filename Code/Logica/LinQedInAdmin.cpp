#include "LinQedInAdmin.h"
#include<typeinfo>

LinQedInAdmin::LinQedInAdmin() {db=new DB();db->load();}

void LinQedInAdmin::insert(Utente *u){
    db->insert(u);
}

void LinQedInAdmin::remove(const string & user) {
    db->remove(user);
}

void LinQedInAdmin::save()const{
    db->save();
}

void LinQedInAdmin::changeSubscriptionType(const string & user,string tipodiutente){
    db->changeSubscriptionType(user,tipodiutente);
}

Utente* LinQedInAdmin::find(const string & user)const {
    return db->find(user);
}

vector <Utente*> LinQedInAdmin::visualizza_utenti_registrati()const {
   return db->visualizza_utenti_registrati();
}
