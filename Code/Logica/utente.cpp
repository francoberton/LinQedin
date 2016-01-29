#include "utente.h"
#include "db.h"
#include "../Grafica/gestionecontatti.h"

Info::Info(string n,string c,string d,string l,string lc,string fs,string ep):Nome(n),Cognome(c),Data_di_Nascita(d),Luogo_di_Nascita(l),Lingue_conosciute(lc),Formazione_Scolastica(fs),Esperienze_Professionali(ep){}

string Info::getNome() const{
    return Nome;
}
string Info::getCognome()const{
    return Cognome;
}
string Info::getData_di_Nascita() const{
    return Data_di_Nascita;
}
string Info::getLuogo_di_Nascita() const{
    return Luogo_di_Nascita;
}
string Info::getLingue_conosciute() const{
    return Lingue_conosciute;
}
string Info::getFormazione_Scolastica() const{
    return Formazione_Scolastica;
}
string Info::getEsperienze_Professionali() const{
    return Esperienze_Professionali;
}

Username::Username(string s,string pw): login(s),password(pw){}

string Username::getlogin() const{
    return login;
}
string Username::getpassword() const{
    return password;
}

Utente::Utente(Username u,Info i):un(u),in(i),rete(new Rete){}

Info Utente::getInfo() const {
    return in;
}
Username Utente::getUsername() const{
    return un;
}
Rete* Utente::getRete() const{
    return rete;
}

void Utente::setRete(Rete* r){
    rete=r;
}

Utente::~Utente(){
    delete rete;
}


bool Rete::add(const string & user) {
  bool found=false;
  for (vector<Username>::iterator it=net.begin();it!=net.end() && !found;it++)
   if(it->getlogin()==user)
      found=true;
  if (!found)
    {net.push_back(user);
    return true;}
  return false;
}

bool Rete::remove(const string & user){
   for (vector<Username>::iterator it=net.begin();it<net.end();it++)
     if (it->getlogin()==user)
        {net.erase(it);
        return true;}
    return false;
}

vector<Username> Rete::getvector() const{
    return net;
}
vector<Username> Rete::setvector(vector<Username>& contacts){
     net=contacts;
     return net;
}

 void Utente::SearchFunctor::operator() (const Utente& x,vector <string>& s) const {
 switch(searchType) {
  case 1:
   {s.push_back("1");
    s.push_back(x.getUsername().getlogin());
    s.push_back(x.getInfo().getNome());
    s.push_back(x.getInfo().getCognome());}
   break;
  case 2:
   {s.push_back("2");
    s.push_back(x.getUsername().getlogin());
    s.push_back(x.getInfo().getNome());
    s.push_back(x.getInfo().getCognome());
    s.push_back(x.getInfo().getData_di_Nascita());
    s.push_back(x.getInfo().getLuogo_di_Nascita());}
   break;
  case 3:
   {s.push_back("3");
    s.push_back(x.getUsername().getlogin());
    s.push_back(x.getInfo().getNome());
    s.push_back(x.getInfo().getCognome());
    s.push_back(x.getInfo().getData_di_Nascita());
    s.push_back(x.getInfo().getLuogo_di_Nascita());
    s.push_back(x.getInfo().getLingue_conosciute());
    s.push_back(x.getInfo().getFormazione_Scolastica());
    s.push_back(x.getInfo().getEsperienze_Professionali());
 }
   break;
   }
}
 UtenteBasic::UtenteBasic(Username u,Info i):Utente(u,i){}
 vector<string> UtenteBasic::userSearch(const DB& d,const string & u) {
    bool found=false;
    vector <string> usersearch;
    for (vector<Utente*>::const_iterator it=d.db.begin();it!=d.db.end() && !found;it++)
      if ((*it)->getUsername().getlogin()==u)
        {found=true;
        SearchFunctor sf(1);
        sf(**it,usersearch);}
     return usersearch;
 }
 UtenteBusiness::UtenteBusiness(Username u,Info i):Utente(u,i){}
 vector<string> UtenteBusiness::userSearch(const DB& d,const string & u){
   bool found=false;
   vector <string> usersearch;
   for (vector<Utente*>::const_iterator it=d.db.begin();it!=d.db.end() && !found;it++)
     if ((*it)->getUsername().getlogin()==u)
      {found=true;
       SearchFunctor sf(2);
       sf(**it,usersearch);}
    return usersearch;;
 }

 UtenteExecutive::UtenteExecutive(Username u,Info i):Utente(u,i){}
 vector<string> UtenteExecutive::userSearch(const DB& d,const string & u){
   bool found=false;
   vector <string> usersearch;
   for (vector<Utente*>::const_iterator it=d.db.begin();it!=d.db.end() && !found;it++)
     if ((*it)->getUsername().getlogin()==u)
      {found=true;
       SearchFunctor sf(3);
       sf(**it,usersearch);}
    return usersearch;

}
