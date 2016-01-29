#include "accessoadmin.h"

AccessoAdmin::AccessoAdmin(LinQedInAdmin* a, QWidget* parent):admin(a){
    this->setStyleSheet("background:qlineargradient(x1:0 y1:0, x2:0 y2:1,stop:0  #3498db, stop:1 #2980b9);color:white;width:350px;" );
    this->setGeometry(250,150,0,0);
    QVBoxLayout* layout=new QVBoxLayout;
    QLabel* gestione_contatti=new QLabel("Gestione utenti");
    gestione_contatti->setAlignment(Qt::AlignHCenter);
    gestione_contatti->setStyleSheet("font: 20pt \"FontAwesome\";" "font-weight:bold;" "background:transparent;"  "margin-bottom:20px;" "margin-top:20px;" );
    QHBoxLayout* layouth=new QHBoxLayout;
    cercautente=new QLineEdit;
    cercautente->setPlaceholderText("Inserisci Username da cercare");
    cercautente->setStyleSheet("background:white;color:black;margin-left:10px;");
    QPushButton* cerca=new QPushButton("Cerca");
    cerca->setStyleSheet("background:#0082b6;max-width:200px;");
    connect(cerca,SIGNAL(clicked()),this,SLOT(find()));
    layouth->addWidget(cercautente);
    layouth->addWidget(cerca);
    QHBoxLayout* layoutc=new QHBoxLayout;
    QVBoxLayout* layoutcdx=new QVBoxLayout;
    output=new QTableWidget;
    output->setStyleSheet("background:white;color:black;max-height:300px;margin-left:10px;margin-bottom:10px;"  );
    output->setColumnCount(6);
    QHeaderView *HorzHdr=output->horizontalHeader();
    HorzHdr->setSectionResizeMode(QHeaderView::Stretch);
    QStringList  headerlabels;
    headerlabels<<"Username"<<"Nome"<<"Cognome"<<"Data di Nascita"<<"Luogo di Nascita"<<"Tipo di Utente";
    output->setHorizontalHeaderLabels(headerlabels);
    output->horizontalHeader()->setStyleSheet("min-height:30px;margin:0px;");
    output->horizontalHeader()->setHighlightSections(false);
    output->verticalHeader()->setVisible(false);
    output->verticalHeader()->setStyleSheet("min-width:60px;");
    output->setEditTriggers( QAbstractItemView::NoEditTriggers );
    output->setSelectionBehavior(QAbstractItemView::SelectRows);
    QPushButton* aggiungi_utente=new QPushButton("Inserimento Utente");
    aggiungi_utente->setStyleSheet("background: #0082b6;max-width:200px;");
    connect(aggiungi_utente,SIGNAL(clicked()),new Registrazione(admin),SLOT(show()));
    QPushButton* rimuovi_utente=new QPushButton("Rimuovi Utente");
    rimuovi_utente->setStyleSheet("background: #0082b6;max-width:200px;");
    connect(rimuovi_utente,SIGNAL(clicked()),this,SLOT(remove_utente()));
    QPushButton* modifica_account=new QPushButton("Modifica Account");
    connect(modifica_account,SIGNAL(clicked()),this,SLOT(modifica_tipologia_utente()));
    modifica_account->setStyleSheet("background: #0082b6;max-width:200px;");
    QPushButton* visualizza_utenti=new QPushButton("Visualizza Utenti Registrati");
    visualizza_utenti->setStyleSheet("background: #0082b6;max-width:200px;");
    connect(visualizza_utenti,SIGNAL(clicked()),this,SLOT(visualizza_utenti_registrati()));
    QPushButton* save_DB=new QPushButton("Save DB");
    save_DB->setStyleSheet("background:#0082b6;max-width:200px;");
    connect(save_DB,SIGNAL(clicked()),this,SLOT(savedb()));
    QPushButton* logout=new QPushButton("Logout");
    logout->setStyleSheet("background: #0082b6;max-width:200px;");


    connect(logout,SIGNAL(clicked()),this,SLOT(close()));
    connect(logout,SIGNAL(clicked()),new MainWindow(),SLOT(show()));
    layoutc->addWidget(output);
    layoutcdx->addWidget(aggiungi_utente);
    layoutcdx->addWidget(rimuovi_utente);
    layoutcdx->addWidget(modifica_account);
    layoutcdx->addWidget(visualizza_utenti);
    layoutcdx->addWidget(save_DB);
    layoutcdx->addWidget(logout,0,Qt::AlignTop);
    layoutc->addLayout(layoutcdx);
    layout->addWidget(gestione_contatti);
    layout->addLayout(layouth);
    layout->addLayout(layoutc);
    layout -> setMargin(0);
    layout -> setContentsMargins (0,0,0,0);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}

void AccessoAdmin::find(){
    Utente* ut=admin->find(cercautente->text().toStdString());
    while (output->rowCount()!=0)
        output->removeRow(0);
    if (ut!=0)
    {output->removeRow(0);
     QTableWidgetItem *username=new QTableWidgetItem (QString::fromStdString(ut->getUsername().getlogin()));
     QTableWidgetItem *nome=new QTableWidgetItem (QString::fromStdString(ut->getInfo().getNome()));
     QTableWidgetItem *cognome=new QTableWidgetItem (QString::fromStdString(ut->getInfo().getCognome()));
     QTableWidgetItem *data_di_nascita=new QTableWidgetItem (QString::fromStdString(ut->getInfo().getData_di_Nascita()));
     QTableWidgetItem *luogo_di_nascita=new QTableWidgetItem (QString::fromStdString(ut->getInfo().getLuogo_di_Nascita()));
     QTableWidgetItem *tipo_di_utente;
     if (dynamic_cast<UtenteBasic*>(ut))
        tipo_di_utente=new QTableWidgetItem ("Utente Basic");
     if (dynamic_cast<UtenteBusiness*>(ut))
        tipo_di_utente=new QTableWidgetItem ("Utente Business");
     if (dynamic_cast<UtenteExecutive*>(ut))
        tipo_di_utente=new QTableWidgetItem ("Utente Executive");
     output->insertRow(0);
     output->setItem(0,0,username);
     output->setItem(0,1,nome);
     output->setItem(0,2,cognome);
     output->setItem(0,3,data_di_nascita);
     output->setItem(0,4,luogo_di_nascita);
     output->setItem(0,5,tipo_di_utente);}
    else
     {QMessageBox * m=new QMessageBox();
      m->setText("Utente non Trovato");
      m->exec();}
}

void AccessoAdmin::remove_utente(){
    bool oggetto_selezionato=false;
    for (int i=0;i<output->rowCount();i++)
        if (output->item(i,0)->isSelected())
           {oggetto_selezionato=true;
            admin->remove(output->item(i,0)->text().toStdString());
            output->removeRow(i);
            QMessageBox * m=new QMessageBox();
            m->setText("Utente rimosso correttamente");
            m->exec();}
    if (!oggetto_selezionato)
       {QMessageBox * m=new QMessageBox();
        m->setText("Utente non selezionato");
        m->exec();}
}

void AccessoAdmin::visualizza_utenti_registrati(){
    while (output->rowCount()!=0)
        output->removeRow(0);
    vector <Utente*> s=admin->visualizza_utenti_registrati();
    for (int i=0;i<s.size();i++)
        {QTableWidgetItem *username=new QTableWidgetItem (QString::fromStdString(s[i]->getUsername().getlogin()));
         QTableWidgetItem *nome=new QTableWidgetItem (QString::fromStdString(s[i]->getInfo().getNome()));
         QTableWidgetItem *cognome=new QTableWidgetItem (QString::fromStdString(s[i]->getInfo().getCognome()));
         QTableWidgetItem *data_di_nascita=new QTableWidgetItem (QString::fromStdString(s[i]->getInfo().getData_di_Nascita()));
         QTableWidgetItem *luogo_di_nascita=new QTableWidgetItem (QString::fromStdString(s[i]->getInfo().getLuogo_di_Nascita()));
         QTableWidgetItem *tipo_di_utente;
         if (dynamic_cast<UtenteBasic*>(s[i]))
            tipo_di_utente=new QTableWidgetItem ("Utente Basic");
         if (dynamic_cast<UtenteBusiness*>(s[i]))
            tipo_di_utente=new QTableWidgetItem ("Utente Business");
         if (dynamic_cast<UtenteExecutive*>(s[i]))
            tipo_di_utente=new QTableWidgetItem ("Utente Executive");
         output->insertRow(0);
         output->setItem(0,0,username);
         output->setItem(0,1,nome);
         output->setItem(0,2,cognome);
         output->setItem(0,3,data_di_nascita);
         output->setItem(0,4,luogo_di_nascita);
         output->setItem(0,5,tipo_di_utente);}
}

 void AccessoAdmin::savedb(){
     admin->save();
     QMessageBox * m=new QMessageBox();
     m->setText("Salvataggio avvenuto con successo");
     m->exec();
 }


 void AccessoAdmin::modifica_tipologia_utente(){
     bool oggetto_selezionato=false;
     for (int i=0;i<output->rowCount();i++)
         if (output->item(i,0)->isSelected())
          {oggetto_selezionato=true;
           Modifica_Tipologia_Utente* mtu=new Modifica_Tipologia_Utente(admin,output->item(i,0)->text().toStdString());
           mtu->gettipologiaUtente(output->item(i,5)->text().toStdString());
           mtu->show();
         }
     if (!oggetto_selezionato)
        {QMessageBox * m=new QMessageBox();
         m->setText("Utente non selezionato");
         m->exec();}
 }


