#ifndef UTENTE_H
#define UTENTE_H
#include<iostream>
#include<vector>
#include<string>
#include <sstream>
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Info{
 public:
  Info(string n="",string c="",string d="",string l="",string lc="",string fs="",string ep="");
  string getNome() const;
  string getCognome()const;
  string getData_di_Nascita() const;
  string getLuogo_di_Nascita() const;
  string getLingue_conosciute() const;
  string getFormazione_Scolastica() const;
  string getEsperienze_Professionali() const;
 private:
  string Nome;
  string Cognome;
  string Data_di_Nascita;
  string Luogo_di_Nascita;
  string Lingue_conosciute;
  string Formazione_Scolastica;
  string Esperienze_Professionali;

};


class Username {
 public:
 Username(string s="",string pw="");
 string getlogin() const;
 string getpassword() const;
 private:
 string login;
 string password;
};

class Rete {
 private:
    vector<Username> net;
 public:
    bool add(const string &);
    bool remove(const string &);
    vector<Username> getvector() const;
    vector<Username> setvector(vector<Username>&);
};


class DB;

class Utente
{
public:
    Utente(Username u,Info i);
    virtual ~Utente();
    // ricerca polimorfa, virtuale pura!
    // contratto: la ricerca permessa dalla propria tipologia di subscription!
    virtual vector<string> userSearch(const DB& d,const string &) =0;
    Info getInfo() const;
    Username getUsername() const;
    Rete* getRete() const;
    void setRete(Rete*);
    protected:
    // classe annidata di funtori di ricerca!
    class SearchFunctor {
     public:
      int searchType;
      SearchFunctor(int x=0): searchType(x) {}
      void operator() (const Utente &x,vector <string>& ) const;
    };
private:
    Info in;
    Rete* rete;
    Username un;
};

class UtenteBasic:public Utente{
public:
    UtenteBasic(Username u,Info i);
    // overriding: ricerca per un utente Basic, funtore di tipo 1
    virtual vector<string> userSearch(const DB& d,const string &);
};

class UtenteBusiness:public Utente{
public:
    UtenteBusiness(Username u,Info i);
    // overriding: ricerca per un utente Business, funtore di tipo 2
    virtual vector<string> userSearch(const DB& d,const string &);

};

class UtenteExecutive:public Utente{
public:
    UtenteExecutive(Username u,Info i);
    // overriding: ricerca per un utente Executive, funtore di tipo 3
    virtual vector<string> userSearch(const DB& d,const string &);
};







#endif // UTENTE_H
