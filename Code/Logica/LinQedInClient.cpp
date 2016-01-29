#include "LinQedInClient.h"

void LinkedInClient::aggiornaProfilo(Utente* agg)
{
    db->modifica_profilo(u,agg);
}

void LinkedInClient::savedb(){
    db->save();
}
/*funzione utilizzata per restituire il contatto cercato*/
Utente* LinkedInClient::find(const string & user)const {
    return db->find(user);
}

bool LinkedInClient::insertRete(const string & un) {
    return u->getRete()->add(un);
}

bool LinkedInClient::removeRete(const string & un) {
    return u->getRete()->remove(un);
}

vector <string> LinkedInClient::ricerca(const string & user) {
    vector <string> usersearch=u->userSearch(*db,user);
    return usersearch;
}

