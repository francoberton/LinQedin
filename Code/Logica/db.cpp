#include "db.h"


void  DB::load(){

    QString filename("../DB.xml");
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text))
     std::cerr << "Error: Cannot read file " << qPrintable(filename)<< ": " << qPrintable(file.errorString())<< std::endl;

    QDomDocument doc;
    if(!doc.setContent(&file))
        return;
    //salvo la radice del documento
    QDomElement docElem = doc.documentElement();
    // creo una lista dei nodi utenti identificati dal tag "user"
    QDomNodeList nodes = docElem.elementsByTagName("Utente");
    // scorro la lista nodo per nodo
    for(int i=0; i<nodes.count(); ++i){

        //salvo l'elemento contenuto nel nodo, in posizione i, in un oggetto xml
        QDomElement el = nodes.at(i).toElement();
        // mi sposto sul primo figlio
        QDomNode nodo = el.firstChild();
        // creo le variabili per l'oggetto user
        QString n, s, un, pw, l,lc,fs,ep, d, t;
        // scorro tutti i tag del nodo e li salvo nelle rispettive variabili
        vector<Username> contacts;
        while (!nodo.isNull()) {
            QDomElement elemento = nodo.toElement();
            QString tagName = elemento.tagName();
            if(tagName=="Nome"){
                n=elemento.text();
            }
            if(tagName=="Cognome"){
                s=elemento.text();
            }
            if(tagName=="Username"){
                un=elemento.text();
            }
            if(tagName=="Password"){
                pw=elemento.text();
            }
            if(tagName=="Data_di_Nascita"){
                d=elemento.text();
            }
            if(tagName=="Luogo_di_Nascita"){
                l=elemento.text();
            }
            if(tagName=="Lingue_conosciute"){
                lc=elemento.text();
            }
            if(tagName=="Formazione_Scolastica"){
                fs=elemento.text();
            }
            if(tagName=="Esperienze_Professionali"){
                ep=elemento.text();
            }
            if(tagName=="Tipo_di_Utente"){
                t=elemento.text();
            }
            if(tagName=="Rete_Contatti"){
               {QDomNode nodocontact = elemento.firstChild();
                  while (!nodocontact.isNull())
                  {QDomElement el = nodocontact.toElement();
                   contacts.push_back(Username(el.text().toStdString()));
                   nodocontact=nodocontact.nextSibling();}
               }
            }
             //mi sposto sul tag successivo
            nodo=nodo.nextSibling();
        }
        Utente* u;
        Info in(n.toStdString(),s.toStdString(),d.toStdString(),l.toStdString(),lc.toStdString(),fs.toStdString(),ep.toStdString());
        if (t=="Utente Basic")
         u=new UtenteBasic(Username(un.toStdString(),pw.toStdString()),in);
       if (t=="Utente Business")
         u=new UtenteBusiness(Username(un.toStdString(),pw.toStdString()),in);
       if (t=="Utente Executive")
         u=new UtenteExecutive(Username(un.toStdString(),pw.toStdString()),in);
       u->getRete()->setvector(contacts);

       db.push_back(u);
    }
    file.close();

}
void DB::save() const {
    QString filename("../DB.xml");
        QFile file(filename);
        file.open(QIODevice::WriteOnly);

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.setDevice(&file);
        xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement("DATABASE");
        for (int i = 0; i <db.size();i++)
        {
         xmlWriter.writeStartElement("Utente");
            xmlWriter.writeTextElement("Username",QString::fromStdString(db[i]->getUsername().getlogin()));
            xmlWriter.writeTextElement("Password",QString::fromStdString(db[i]->getUsername().getpassword()));
            xmlWriter.writeTextElement("Nome",QString::fromStdString(db[i]->getInfo().getNome()));
            xmlWriter.writeTextElement("Cognome",QString::fromStdString(db[i]->getInfo().getCognome()));
            xmlWriter.writeTextElement("Data_di_Nascita",QString::fromStdString(db[i]->getInfo().getData_di_Nascita()));
            xmlWriter.writeTextElement("Luogo_di_Nascita",QString::fromStdString(db[i]->getInfo().getLuogo_di_Nascita()));
            xmlWriter.writeTextElement("Lingue_conosciute",QString::fromStdString(db[i]->getInfo().getLingue_conosciute()));
            xmlWriter.writeTextElement("Formazione_Scolastica",QString::fromStdString(db[i]->getInfo(). getFormazione_Scolastica()));
            xmlWriter.writeTextElement("Esperienze_Professionali",QString::fromStdString(db[i]->getInfo(). getEsperienze_Professionali()));
            if (dynamic_cast<UtenteBasic*>(db[i]))
                xmlWriter.writeTextElement("Tipo_di_Utente","Utente Basic");
            if (dynamic_cast<UtenteBusiness*>(db[i]))
                xmlWriter.writeTextElement("Tipo_di_Utente","Utente Business");
            if (dynamic_cast<UtenteExecutive*>(db[i]))
                xmlWriter.writeTextElement("Tipo_di_Utente","Utente Executive");
            xmlWriter.writeStartElement("Rete_Contatti");
           const vector<Username> & contacts=db[i]->getRete()->getvector();
           for (vector<Username>::const_iterator it=contacts.begin();it!=contacts.end();it++)
                xmlWriter.writeTextElement("Contact",QString::fromStdString(it->getlogin()));
            xmlWriter.writeEndElement();
         xmlWriter.writeEndElement();
        }

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
        file.close();
}

Utente* DB::find(const string & user){
    for(vector<Utente*>::iterator it=db.begin(); it!=db.end(); ++it){
        if(user==(*it)->getUsername().getlogin())
            return *it;
    }
    return 0;
}

void DB::insert(Utente *u){
    db.push_back(u);
 }

void DB::remove(const string& user){
    vector<Utente*>::iterator d;
    for (vector<Utente*>::iterator it=db.begin();it<db.end();it++)
     {vector<Username> contacts=(*it)->getRete()->getvector();
     for (vector<Username>::iterator u=contacts.begin();u<contacts.end();u++)
       {if (u->getlogin()==user)
            contacts.erase(u);
            (*it)->getRete()->setvector(contacts);
        }
      if ((*it)->getUsername().getlogin()==user)
         d=it;
      }
    delete *d;
    db.erase(d);
}

void DB::changeSubscriptionType(const string& user,string tipodiutente){
    for (vector<Utente*>::iterator it=db.begin();it<db.end();it++)
     if ((*it)->getUsername().getlogin()==user)
        {Info in=(*it)->getInfo();
         Username u=(*it)->getUsername();
         Rete* r=new Rete(*((*it)->getRete()));
         delete *it;
         if (tipodiutente=="Utente Basic")
            *it=new UtenteBasic(u,in);
         if (tipodiutente=="Utente Business")
            *it=new UtenteBusiness(u,in);
         if (tipodiutente=="Utente Executive")
            *it=new UtenteExecutive(u,in);
         (*it)->setRete(r);
        }
}

Utente* DB::autentication(Username user){
    for(vector<Utente*>::iterator it=db.begin(); it!=db.end(); ++it){
     if ((*it)->getUsername().getlogin()==user.getlogin() && (*it)->getUsername().getpassword()==user.getpassword())
         return *it;
    }
 return 0;
}

vector<Utente*> DB::visualizza_utenti_registrati() const {
    vector<Utente*> v;
    for (int i=0;i<db.size();i++)
        v.push_back(db[i]);
    return v;
}

void DB::modifica_profilo(Utente* u,Utente* mod){
    for(vector<Utente*>::iterator it=db.begin(); it!=db.end(); ++it)
     if ((*it)->getUsername().getlogin()==u->getUsername().getlogin())
        {mod->setRete((*it)->getRete());
         **it=*mod;}
}
