#include "gestionecontatti.h"

GestioneContatti::GestioneContatti(LinkedInClient* c, QWidget* parent):client(c){
    this->setStyleSheet("background:qlineargradient(x1:0 y1:0, x2:0 y2:1,stop:0  #3498db, stop:1 #2980b9);color:white;width:470px;max-height:350px;" );
    this->setGeometry(150,150,0,0);
    QVBoxLayout* layout=new QVBoxLayout;
    QLabel* gestione_contatti=new QLabel("Gestione contatti");
    gestione_contatti->setAlignment(Qt::AlignHCenter);
    gestione_contatti->setStyleSheet("font: 20pt \"FontAwesome\";background:transparent; font-weight:bold; margin-bottom:20px;margin-top:20px;" );
    QVBoxLayout* layoutsx=new QVBoxLayout;
    LEcerca=new QLineEdit;
    LEcerca->setStyleSheet("background:white;" "color:black;" );
    LEcerca->setPlaceholderText("Inserisci Username da cercare");
    QHBoxLayout* container=new QHBoxLayout;
    QVBoxLayout* layoutdx=new QVBoxLayout;
    container->setContentsMargins(5,0,0,5);
    output=new QTableWidget;
    output->setStyleSheet("background:white;color:black;" );
    output->setColumnCount(8);
    QHeaderView *HorzHdr=output->horizontalHeader();
    HorzHdr->setSectionResizeMode(QHeaderView::Stretch);
    QStringList  headerlabels;
    headerlabels<<"Username"<<"Nome"<<"Cognome"<<"Data di Nascita"<<"Luogo di Nascita"<<"Tipo di Utente"<<"Curriculum"<<"Rete";
    output->setHorizontalHeaderLabels(headerlabels);
    output->horizontalHeader()->setHighlightSections(false);
    output->verticalHeader()->setVisible(false);
    output->setEditTriggers( QAbstractItemView::NoEditTriggers );
    output->setSelectionBehavior(QAbstractItemView::SelectRows);
    QPushButton* cerca=new QPushButton("Cerca");
    cerca->setStyleSheet("background:#0082b6;max-height:25px;max-width:150px;");
    connect(cerca,SIGNAL(clicked()),this,SLOT(find()));
    QPushButton* aggiungi_contatto=new QPushButton("Aggiungi Contatto");
    connect(aggiungi_contatto,SIGNAL(clicked()),this,SLOT(add_contact()));
    aggiungi_contatto->setStyleSheet("background:#0082b6;max-height:25px;max-width:150px;");
    QPushButton* rimuovi_contatto=new QPushButton("Rimuovi Contatto");
    connect(rimuovi_contatto,SIGNAL(clicked()),this,SLOT(remove_contact()));
    rimuovi_contatto->setStyleSheet("background:#0082b6;max-height:25px;max-width:150px;");
    QPushButton* visualizza_contatti=new QPushButton("Visualizza Contatti");
    visualizza_contatti->setStyleSheet("background:#0082b6;max-height:25px;max-width:150px;");
    connect(visualizza_contatti,SIGNAL(clicked()),this,SLOT(visualizza_contacts()));
    QPushButton* savedb=new QPushButton("Save DB");
    savedb->setStyleSheet("background:#0082b6;max-height:25px;max-width:150px;");
    connect(savedb,SIGNAL(clicked()),this,SLOT(save_DB()));
    QPushButton* button_back=new QPushButton("Back");
    button_back->setStyleSheet("background:#0082b6;max-width:150px;");
    connect(button_back,SIGNAL(clicked()),this,SLOT(close()));
    connect(button_back,SIGNAL(clicked()),parent,SLOT(show()));

    layoutsx->addWidget(LEcerca);
    layoutsx->addWidget(output);
    layoutsx->setContentsMargins(5,0,0,0);
    layoutdx->addWidget(cerca);
    layoutdx->addWidget(aggiungi_contatto);
    layoutdx->addWidget(rimuovi_contatto);
    layoutdx->addWidget(visualizza_contatti);
    layoutdx->addWidget(savedb);
    layoutdx->addWidget(button_back,0,Qt::AlignTop);
    layoutdx->setContentsMargins(0,0,0,0);
    container->addLayout(layoutsx);
    container->addLayout(layoutdx);
    layout->addWidget(gestione_contatti);
    layout->addLayout(container);
    layout -> setMargin(0);
    layout -> setContentsMargins (0,0,0,0);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}


void GestioneContatti::add_contact(){
    bool oggetto_selezionato=false;
    for (int i=0;i<output->rowCount();i++)
        if (output->item(i,0)->isSelected())
           {oggetto_selezionato=true;
           if (client->insertRete(output->item(i,0)->text().toStdString()))
            {QMessageBox * m=new QMessageBox();
             m->setText("Contatto aggiunto con successo");
             m->exec();}
           else
            {QMessageBox * m=new QMessageBox();
             m->setText("Utente già aggiunto");
             m->exec();}}
    if (!oggetto_selezionato)
       {QMessageBox * m=new QMessageBox();
        m->setText("Utente non selezionato");
        m->exec();}
}

void GestioneContatti::remove_contact(){
    bool oggetto_selezionato=false;
    for (int i=0;i<output->rowCount();i++)
        if (output->item(i,0)->isSelected())
           {oggetto_selezionato=true;
            if(client->removeRete(output->item(i,0)->text().toStdString()))
             {output->removeRow(i);
              QMessageBox * m=new QMessageBox();
              m->setText("Contatto rimosso con successo");
              m->exec();}
            else
             {QMessageBox * m=new QMessageBox();
              m->setText("Utente non presente nella rete contatti");
              m->exec();}
            }
    if (!oggetto_selezionato)
       {QMessageBox * m=new QMessageBox();
        m->setText("Utente non selezionato");
        m->exec();}
}

void GestioneContatti::visualizza_contacts(){
    while (output->rowCount()!=0)
           output->removeRow(0);
    const vector<Username> & contacts=client->u->getRete()->getvector();
    for (vector<Username>::const_iterator it=contacts.begin();it!=contacts.end();it++)
       {vector<string> s=client->ricerca(it->getlogin());
        if (s.empty())
           {QMessageBox * m=new QMessageBox();
            m->setText("Utente non Trovato");
            m->exec();}
        else{
         if (s[0]=="1")
           {QTableWidgetItem *username=new QTableWidgetItem (QString::fromStdString(s[1]));
            QTableWidgetItem *nome=new QTableWidgetItem (QString::fromStdString(s[2]));
            QTableWidgetItem *cognome=new QTableWidgetItem (QString::fromStdString(s[3]));
            output->insertRow(0);
            output->setItem(0,0,username);
            output->setItem(0,1,nome);
            output->setItem(0,2,cognome);}
         if (s[0]=="2")
           {QTableWidgetItem* username=new QTableWidgetItem (QString::fromStdString(s[1]));
            QTableWidgetItem* nome=new QTableWidgetItem (QString::fromStdString(s[2]));
            QTableWidgetItem* cognome=new QTableWidgetItem (QString::fromStdString(s[3]));
            QTableWidgetItem* data_di_nascita=new QTableWidgetItem (QString::fromStdString(s[4]));
            QTableWidgetItem* luogo_di_nascita=new QTableWidgetItem (QString::fromStdString(s[5]));
            QTableWidgetItem* tipo_di_utente=new QTableWidgetItem ("Utente Business");
            output->insertRow(0);
            output->setItem(0,0,username);
            output->setItem(0,1,nome);
            output->setItem(0,2,cognome);
            output->setItem(0,3,data_di_nascita);
            output->setItem(0,4,luogo_di_nascita);
            output->setItem(0,5,tipo_di_utente);}
         if (s[0]=="3")
           {QTableWidgetItem* username=new QTableWidgetItem (QString::fromStdString(s[1]));
            QTableWidgetItem* nome=new QTableWidgetItem (QString::fromStdString(s[2]));
            QTableWidgetItem* cognome=new QTableWidgetItem (QString::fromStdString(s[3]));
            QTableWidgetItem* data_di_nascita=new QTableWidgetItem (QString::fromStdString(s[4]));
            QTableWidgetItem* luogo_di_nascita=new QTableWidgetItem (QString::fromStdString(s[5]));
            QTableWidgetItem* tipo_di_utente=new QTableWidgetItem ("Utente Executive");
            QPushButton* visualizza_curriculum=new QPushButton("Curriculum");
            visualizza_curriculum->setStyleSheet("background:gray;");
            connect(visualizza_curriculum,SIGNAL(clicked()),new Curriculum(client,s[6],s[7],s[8]),SLOT(show()));
            QPushButton* visualizza_rete=new QPushButton("Rete");
            visualizza_rete->setStyleSheet("background:gray");
            connect(visualizza_rete,SIGNAL(clicked()),new Rete_Contatto(client,s[1]),SLOT(show()));
            output->insertRow(0);
            output->setItem(0,0,username);
            output->setItem(0,1,nome);
            output->setItem(0,2,cognome);
            output->setItem(0,3,data_di_nascita);
            output->setItem(0,4,luogo_di_nascita);
            output->setItem(0,5,tipo_di_utente);
            output->setCellWidget(0,6,visualizza_curriculum);
            output->setCellWidget(0,7,visualizza_rete);
           }
        }
     }
     if (!client->u->getRete()->getvector().size())
     {QMessageBox * m=new QMessageBox();
      m->setText("Lista Contatti Vuota");
      m->exec();}

}

void GestioneContatti::save_DB(){
    client->savedb();
    QMessageBox * m=new QMessageBox();
    m->setText("Salvataggio avvenuto con successo");
    m->exec();
}


void GestioneContatti::find(){
   while (output->rowCount()!=0)
           output->removeRow(0);
   vector<string> s;
   if (client->u->getUsername().getlogin()==LEcerca->text().toStdString())
        {QMessageBox * m=new QMessageBox();
         m->setText("Non è possibile cercare se stessi!");
         m->exec();}
   else
     {s=client->ricerca(LEcerca->text().toStdString());
   if (s.empty())
     {QMessageBox * m=new QMessageBox();
      m->setText("Utente non Trovato");
      m->exec();}
    else{
      if (s[0]=="1")
         {QTableWidgetItem *username=new QTableWidgetItem (QString::fromStdString(s[1]));
          QTableWidgetItem *nome=new QTableWidgetItem (QString::fromStdString(s[2]));
          QTableWidgetItem *cognome=new QTableWidgetItem (QString::fromStdString(s[3]));
          output->insertRow(0);
          output->setItem(0,0,username);
          output->setItem(0,1,nome);
          output->setItem(0,2,cognome);}
      if (s[0]=="2")
         {QTableWidgetItem *username=new QTableWidgetItem (QString::fromStdString(s[1]));
          QTableWidgetItem *nome=new QTableWidgetItem (QString::fromStdString(s[2]));
          QTableWidgetItem *cognome=new QTableWidgetItem (QString::fromStdString(s[3]));
          QTableWidgetItem *data_di_nascita=new QTableWidgetItem (QString::fromStdString(s[4]));
          QTableWidgetItem *luogo_di_nascita=new QTableWidgetItem (QString::fromStdString(s[5]));
          QTableWidgetItem *tipo_di_utente=new QTableWidgetItem (QString::fromStdString("Utente Business"));
          output->insertRow(0);
          output->setItem(0,0,username);
          output->setItem(0,1,nome);
          output->setItem(0,2,cognome);
          output->setItem(0,3,data_di_nascita);
          output->setItem(0,4,luogo_di_nascita);
          output->setItem(0,5,tipo_di_utente);}
      if (s[0]=="3")
         {QTableWidgetItem *username=new QTableWidgetItem (QString::fromStdString(s[1]));
          QTableWidgetItem *nome=new QTableWidgetItem (QString::fromStdString(s[2]));
          QTableWidgetItem *cognome=new QTableWidgetItem (QString::fromStdString(s[3]));
          QTableWidgetItem *data_di_nascita=new QTableWidgetItem (QString::fromStdString(s[4]));
          QTableWidgetItem *luogo_di_nascita=new QTableWidgetItem (QString::fromStdString(s[5]));
          QTableWidgetItem *tipo_di_utente=new QTableWidgetItem (QString::fromStdString("Utente Executive"));
          QPushButton* visualizza_curriculum=new QPushButton("Curriculum");
          visualizza_curriculum->setStyleSheet("background:gray;");
          connect(visualizza_curriculum,SIGNAL(clicked()),new Curriculum(client,s[6],s[7],s[8]),SLOT(show()));
          QPushButton* visualizza_rete=new QPushButton("Rete");
          visualizza_rete->setStyleSheet("background:gray");
          connect(visualizza_rete,SIGNAL(clicked()),new Rete_Contatto(client,s[1]),SLOT(show()));
          output->insertRow(0);
          output->setItem(0,0,username);
          output->setItem(0,1,nome);
          output->setItem(0,2,cognome);
          output->setItem(0,3,data_di_nascita);
          output->setItem(0,4,luogo_di_nascita);
          output->setItem(0,5,tipo_di_utente);
          output->setCellWidget(0,6,visualizza_curriculum);
          output->setCellWidget(0,7,visualizza_rete); }
    }
   }
}


Rete_Contatto::Rete_Contatto(LinkedInClient* c,string user,QWidget* parent):client(c),contact(user){
    this->setStyleSheet("background:qlineargradient(x1:0 y1:0, x2:0 y2:1,stop:0  #3498db, stop:1 #2980b9);color:white;width:470px;max-height:250px;" );
    this->setGeometry(200,180,0,0);
    QVBoxLayout* layout=new QVBoxLayout;
    QLabel* title=new QLabel("Rete Contatto");
    title->setAlignment(Qt::AlignHCenter);
    title->setStyleSheet("font: 20pt \"FontAwesome\";background:transparent; font-weight:bold; margin-bottom:20px;margin-top:20px;" );
    rete_contatto=new QTableWidget();
    rete_contatto->setColumnCount(7);
    rete_contatto->setStyleSheet("background:white;" "color:black;" );
    QHeaderView *HorzHdr=rete_contatto->horizontalHeader();
    HorzHdr->setSectionResizeMode(QHeaderView::Stretch);
    QStringList  headerlabels;
    headerlabels<<"Username"<<"Nome"<<"Cognome"<<"Data di Nascita"<<"Luogo di Nascita"<<"Tipo di Utente"<<"Curriculum";
    rete_contatto->setHorizontalHeaderLabels(headerlabels);
    rete_contatto->horizontalHeader()->setHighlightSections(false);
    rete_contatto->verticalHeader()->setVisible(false);
    rete_contatto->setSelectionBehavior(QAbstractItemView::SelectRows);
    visualizza_rete_contatto();
    QHBoxLayout* pulsante=new QHBoxLayout;
    QPushButton* close=new QPushButton("Close");
    close->setStyleSheet("background:#0082b6;max-width:150px;margin:0auto;");
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    pulsante->addWidget(close);

    layout->addWidget(title);
    layout->addWidget(rete_contatto);
    layout->addLayout(pulsante);
    layout->setContentsMargins(5,0,5,5);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}

void Rete_Contatto::visualizza_rete_contatto(){
    Utente* ut=client->find(contact);
    const vector<Username>& contacts=ut->getRete()->getvector();
    for (vector<Username>::const_iterator it=contacts.begin();it!=contacts.end();it++)
           {Utente* u=client->find(it->getlogin());
            QTableWidgetItem *username=new QTableWidgetItem (QString::fromStdString(u->getUsername().getlogin()));
            QTableWidgetItem *nome=new QTableWidgetItem (QString::fromStdString(u->getInfo().getNome()));
            QTableWidgetItem *cognome=new QTableWidgetItem (QString::fromStdString(u->getInfo().getCognome()));
            QTableWidgetItem *data_di_nascita=new QTableWidgetItem (QString::fromStdString(u->getInfo().getData_di_Nascita()));
            QTableWidgetItem *luogo_di_nascita=new QTableWidgetItem (QString::fromStdString(u->getInfo().getLuogo_di_Nascita()));
            QTableWidgetItem *tipo_di_utente;
            if (dynamic_cast<UtenteBasic*>(u))
               tipo_di_utente=new QTableWidgetItem ("Utente Basic");
            if (dynamic_cast<UtenteBusiness*>(u))
               tipo_di_utente=new QTableWidgetItem ("Utente Business");
            if (dynamic_cast<UtenteExecutive*>(u))
               tipo_di_utente=new QTableWidgetItem ("Utente Executive");
            QPushButton* visualizza_curriculum=new QPushButton("Curriculum");
            visualizza_curriculum->setStyleSheet("background:gray;");
            connect(visualizza_curriculum,SIGNAL(clicked()),new Curriculum(client,u->getInfo().getLingue_conosciute(),u->getInfo().getFormazione_Scolastica(),u->getInfo().getEsperienze_Professionali()),SLOT(show()));
            rete_contatto->insertRow(0);
            rete_contatto->setItem(0,0,username);
            rete_contatto->setItem(0,1,nome);
            rete_contatto->setItem(0,2,cognome);
            rete_contatto->setItem(0,3,data_di_nascita);
            rete_contatto->setItem(0,4,luogo_di_nascita);
            rete_contatto->setItem(0,5,tipo_di_utente);
            rete_contatto->setCellWidget(0,6,visualizza_curriculum);
           }
    }

Curriculum::Curriculum(LinkedInClient* c,string L_C,string F_S,string E_P,QWidget *parent):client(c){
    this->setStyleSheet("background:qlineargradient(x1:0 y1:0, x2:0 y2:1,stop:0  #3498db, stop:1 #2980b9);color:white;width:200px;max-height:200px;" );
    this->setGeometry(500,50,0,0);
    QVBoxLayout* layout=new QVBoxLayout;
    QLabel* title=new QLabel("Curriculum");
    title->setAlignment(Qt::AlignHCenter);
    title->setStyleSheet("font: 20pt \"FontAwesome\";background:transparent; font-weight:bold; margin-bottom:20px;margin-top:20px;" );
    QLabel* Label_LC=new QLabel("Lingue conosciute:");
    Label_LC->setStyleSheet("background:transparent;");
    QTextEdit* Lingue_Conosciute=new QTextEdit();
    Lingue_Conosciute->setPlainText(QString::fromStdString(L_C));
    Lingue_Conosciute->setStyleSheet("background:white;color:black;max-height:150px;" );
    Lingue_Conosciute->setReadOnly(true);
    QLabel* Label_FS=new QLabel("Formazione Scolastica:");
    Label_FS->setStyleSheet("background:transparent;");
    QTextEdit* Formazione_Scolastica=new QTextEdit();
    Formazione_Scolastica->setStyleSheet("background:white;color:black;max-height:150px;" );
    Formazione_Scolastica->setPlainText(QString::fromStdString(F_S));
    Formazione_Scolastica->setReadOnly(true);
    QLabel* Label_EP=new QLabel("Esperienze Professionali:");
    Label_EP->setStyleSheet("background:transparent;");
    QTextEdit* Esperienze_Professionali=new QTextEdit();
    Esperienze_Professionali->setStyleSheet("background:white;color:black;max-height:150px;" );
    Esperienze_Professionali->setPlainText(QString::fromStdString(E_P));
    Esperienze_Professionali->setReadOnly(true);
    QHBoxLayout* pulsante=new QHBoxLayout;
    QPushButton* close=new QPushButton("Close");
    close->setStyleSheet("background:#0082b6;max-width:150px;margin:0auto;");
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    pulsante->addWidget(close);

    layout->addWidget(title);
    layout->addWidget(Label_LC);
    layout->addWidget(Lingue_Conosciute);
    layout->addWidget(Label_FS);
    layout->addWidget(Formazione_Scolastica);
    layout->addWidget(Label_EP);
    layout->addWidget(Esperienze_Professionali);
    layout->addLayout(pulsante);
    layout->setContentsMargins(5,0,5,5);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}

