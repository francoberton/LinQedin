#include "gestioneprofilou.h"

GestioneProfiloU::GestioneProfiloU(LinkedInClient* c, QWidget* parent):client(c){
    this->setStyleSheet("background:qlineargradient(x1:0 y1:0, x2:0 y2:1,stop:0  #3498db, stop:1 #2980b9);color:white;width:470px;min-height:70px;" );
    this->setGeometry(130,0,0,0);
    QVBoxLayout* layout=new QVBoxLayout;
    QLabel* gestione_contatti=new QLabel("Gestione profilo");
    gestione_contatti->setAlignment(Qt::AlignHCenter);
    gestione_contatti->setStyleSheet("font: 20pt \"FontAwesome\"; font-weight:bold; background:transparent;padding-bottom:-10px; padding-top:20px;");
    QHBoxLayout* layoutc=new QHBoxLayout;
    QLabel* nome=new QLabel("Nome:");
    nome->setStyleSheet("background:transparent;padding-bottom:-20px;padding-top:-20px;");
    QLabel* cognome=new QLabel("Cognome:");
    cognome->setStyleSheet("background:transparent;padding-bottom:-20px;padding-top:-20px;");
    QLabel* datadinascita=new QLabel("Data  di Nascita:");
    datadinascita->setWordWrap(1);
    datadinascita->setStyleSheet("background:transparent;padding-bottom:-20px;padding-top:-20px;");
    QLabel* luogodinascita=new QLabel("Luogo di Nascita:");
    luogodinascita->setWordWrap(1);
    luogodinascita->setStyleSheet("background:transparent;padding-bottom:-20px;padding-top:-20px;");
    QLabel* lingue_conosciute=new QLabel("Lingue conosciute:");
    lingue_conosciute->setWordWrap(1);
    lingue_conosciute->setStyleSheet("background:transparent;padding-bottom:-20px;padding-top:-20px;");
    QLabel* formazione_scolastica=new QLabel("Formazione Scolastica:");
    formazione_scolastica->setWordWrap(1);
    formazione_scolastica->setStyleSheet("background:transparent;padding-bottom:-20px;padding-top:-20px;");
    QLabel* esperienze_professionali=new QLabel ("Esperienze professionali:");
    esperienze_professionali->setWordWrap(1);
    esperienze_professionali->setStyleSheet("background:transparent;padding-bottom:-20px;padding-top:-20px;");
    QLabel* username=new QLabel("Username:");
    username->setStyleSheet("background:transparent;padding-bottom:-20px;padding-top:-20px;");
    QLabel* password=new QLabel("Password:");
    password->setStyleSheet("background:transparent;padding-bottom:-20px;padding-top:-20px;");
    cnome=new QLineEdit();
    cnome->setStyleSheet("background:white; color:black;padding-bottom:-25px;padding-top:-25px;max-width:200px;");
    ccognome=new QLineEdit();
    ccognome->setStyleSheet("background:white;color:black;padding-bottom:-25px;padding-top:-25px;max-width:200px;" );
    cdatadinascita=new QLineEdit();
    cdatadinascita->setStyleSheet("background:white;color:black;padding-bottom:-25px;padding-top:-25px; max-width:200px;" );
    cluogodinascita=new QLineEdit();
    cluogodinascita->setStyleSheet("background:white; color:black;padding-bottom:-25px;padding-top:-25px;max-width:200px;" );
    clingue_conosciute=new QTextEdit();
    clingue_conosciute->setStyleSheet("background:white;color:black;max-height:80px;max-width:200px;" );
    cformazione_scolastica=new QTextEdit();
    cformazione_scolastica->setStyleSheet("background:white;color:black;max-height:80px;max-width:200px;" );
    cesperienze_professionali=new QTextEdit();
    cesperienze_professionali->setStyleSheet("background:white;color:black;max-height:80px;max-width:200px;" );
    cusername=new QLineEdit();
    cusername->setStyleSheet("background:white;color:black;padding-bottom:-25px;padding-top:-25px;max-width:200px;" );
    cpassword=new QLineEdit();
    cpassword->setStyleSheet("background:white;color:black;padding-bottom:-25px;padding-top:-25px;max-width:200px;" );
    cpassword->setEchoMode(QLineEdit::Password);
    show_password=new QCheckBox("Show password", this);
    show_password->setStyleSheet("background:transparent; padding-top:-20px;padding-bottom:-20px;");
    show_password->setMaximumWidth(295);
    connect(show_password,SIGNAL(stateChanged(int)),this,SLOT(showpassword()));
    output=new QTableWidget;
    output->setColumnCount(8);
    QHeaderView *HorzHdr=output->horizontalHeader();
    HorzHdr->setSectionResizeMode(QHeaderView::Stretch);
    QStringList  headerlabels;
    headerlabels<<"Username"<<"Nome"<<"Cognome"<<"Data di Nascita"<<" Luogo di Nascita "<<"Tipo di Utente"<<"Curriculum"<<"Rete";
    output->setHorizontalHeaderLabels(headerlabels);
    output->verticalHeader()->setVisible(false);
    output->horizontalHeader()->setStyleSheet("min-height:30px;margin:0px;");
    output->horizontalHeader()->setHighlightSections(false);
    output->setStyleSheet("background:white; color:black;max-height:200px;" );
    output->setEditTriggers( QAbstractItemView::NoEditTriggers );
    output->setSelectionBehavior(QAbstractItemView::SelectRows);
    QPushButton* modifica_profilo=new QPushButton("Modifica Profilo");
    modifica_profilo->setStyleSheet("max-width:130px;padding-top:-20px;padding-bottom:-20px; margin-right:10px;margin-left:10px; background: #0082b6");
    connect(modifica_profilo,SIGNAL(clicked()),this,SLOT(modifica_dati()));
    QPushButton* save_db=new QPushButton("Save DB");
    save_db->setStyleSheet("max-width:130px;padding-top:-20px;padding-bottom:-20px; margin-right:10px;margin-left:10px; background: #0082b6");
    connect(save_db,SIGNAL(clicked()),this,SLOT(savedb()));
    QPushButton* button_back=new QPushButton("Back");
    button_back->setStyleSheet("max-width:130px; padding-top:-20px;padding-bottom:-20px;margin-right:10px;margin-left:10px; background: #0082b6");
    connect(button_back,SIGNAL(clicked()),this,SLOT(close()));
    connect(button_back,SIGNAL(clicked()),parent,SLOT(show()));

    QVBoxLayout* BoxNome=new QVBoxLayout;
    QVBoxLayout* BoxCognome=new QVBoxLayout;
    QHBoxLayout* BoxNomeCognomeUsername=new QHBoxLayout;
    QVBoxLayout* BoxDatadiNascita=new QVBoxLayout;
    QVBoxLayout* BoxLuogodiNascita=new QVBoxLayout;
    QHBoxLayout* BoxDataLuogodiNascita_Password=new QHBoxLayout;
    QVBoxLayout* BoxLingueConosciute=new QVBoxLayout;
    QVBoxLayout* BoxFormazione_Scolastica=new QVBoxLayout;
    QVBoxLayout* BoxEsperienze_Professionali=new QVBoxLayout;
    QHBoxLayout* BoxLingue_Formazione_Esperienze=new QHBoxLayout;
    QVBoxLayout* BoxUsername=new QVBoxLayout;
    QVBoxLayout* BoxPassword=new QVBoxLayout;
    QHBoxLayout* BoxShow_Password=new QHBoxLayout;
    QHBoxLayout* BoxOutput=new QHBoxLayout;
    QVBoxLayout* BoxPulsanti=new QVBoxLayout;
    QVBoxLayout* BoxDatiPersonali_ReteContatti=new QVBoxLayout;
    QHBoxLayout* BoxDatiPulsanti =new QHBoxLayout;
    QLabel* Dati_Personali=new QLabel("Dati Personali");
    Dati_Personali->setAlignment(Qt::AlignHCenter);
    Dati_Personali->setStyleSheet("font: 15pt \"FontAwesome\"; font-weight:bold; background:transparent;padding-bottom:-30px; padding-top:0px;");
    BoxNome->addWidget(nome);
    BoxNome->addWidget(cnome);
    BoxCognome->addWidget(cognome);
    BoxCognome->addWidget(ccognome);
    BoxUsername->addWidget(username);
    BoxUsername->addWidget(cusername);
    BoxNomeCognomeUsername->addLayout(BoxNome);
    BoxNomeCognomeUsername->addLayout(BoxCognome);
    BoxNomeCognomeUsername->addLayout(BoxUsername);
    BoxNomeCognomeUsername->setContentsMargins(10,0,10,0);
    BoxDatadiNascita->addWidget(datadinascita);
    BoxDatadiNascita->addWidget(cdatadinascita);
    BoxLuogodiNascita->addWidget(luogodinascita);
    BoxLuogodiNascita->addWidget(cluogodinascita);
    BoxPassword->addWidget(password);
    BoxPassword->addWidget(cpassword);
    BoxDataLuogodiNascita_Password->addLayout(BoxDatadiNascita);
    BoxDataLuogodiNascita_Password->addLayout(BoxLuogodiNascita);
    BoxDataLuogodiNascita_Password->addLayout(BoxPassword);
    BoxDataLuogodiNascita_Password->setContentsMargins(10,0,10,0);
    BoxLingueConosciute->addWidget(lingue_conosciute);
    BoxLingueConosciute->addWidget(clingue_conosciute);
    BoxFormazione_Scolastica->addWidget(formazione_scolastica);
    BoxFormazione_Scolastica->addWidget(cformazione_scolastica);
    BoxEsperienze_Professionali->addWidget(esperienze_professionali);
    BoxEsperienze_Professionali->addWidget(cesperienze_professionali);
    BoxLingue_Formazione_Esperienze->addLayout(BoxLingueConosciute);
    BoxLingue_Formazione_Esperienze->addLayout(BoxFormazione_Scolastica);
    BoxLingue_Formazione_Esperienze->addLayout(BoxEsperienze_Professionali);
    BoxLingue_Formazione_Esperienze->setContentsMargins(5,0,5,0);
    BoxShow_Password->addWidget(show_password);
    BoxShow_Password->setAlignment(Qt::AlignRight);
    BoxOutput->addWidget(output);
    BoxOutput->setContentsMargins(5,0,5,5);

    QLabel* Rete_contatti=new QLabel("Rete Contatti");
    Rete_contatti->setAlignment(Qt::AlignHCenter);
    Rete_contatti->setStyleSheet("font: 15pt \"FontAwesome\"; font-weight:bold; background:transparent;padding-bottom:-20px; padding-top:20px;");
    BoxDatiPersonali_ReteContatti->addWidget(Dati_Personali);
    BoxDatiPersonali_ReteContatti->addLayout(BoxNomeCognomeUsername);
    BoxDatiPersonali_ReteContatti->addLayout(BoxDataLuogodiNascita_Password);
    BoxDatiPersonali_ReteContatti->addLayout(BoxShow_Password);
    BoxDatiPersonali_ReteContatti->addLayout(BoxLingue_Formazione_Esperienze);
    BoxDatiPersonali_ReteContatti->addWidget(Rete_contatti);
    BoxDatiPersonali_ReteContatti->addLayout(BoxOutput);
    BoxPulsanti->addWidget(modifica_profilo);
    BoxPulsanti->addWidget(save_db);
    BoxPulsanti->addWidget(button_back,0,Qt::AlignTop);
    BoxPulsanti->setContentsMargins(0,58,0,0);
    BoxDatiPulsanti->addLayout(BoxDatiPersonali_ReteContatti);
    BoxDatiPulsanti->addLayout(BoxPulsanti);
    layout->addWidget(gestione_contatti);
    layout->addLayout(BoxDatiPulsanti);
    layout -> setMargin(0);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);

}

void GestioneProfiloU::visualizzaprofilo(){
         cnome->setText(QString::fromStdString(client->u->getInfo().getNome()));
         ccognome->setText(QString::fromStdString(client->u->getInfo().getCognome()));
         cdatadinascita->setText(QString::fromStdString(client->u->getInfo().getData_di_Nascita()));
         cluogodinascita->setText(QString::fromStdString(client->u->getInfo().getLuogo_di_Nascita()));
         cusername->setText(QString::fromStdString(client->u->getUsername().getlogin()));
         cpassword->setText(QString::fromStdString(client->u->getUsername().getpassword()));
         clingue_conosciute->setText(QString::fromStdString(client->u->getInfo().getLingue_conosciute()));
         cformazione_scolastica->setText(QString::fromStdString(client->u->getInfo().getFormazione_Scolastica()));
         cesperienze_professionali->setText(QString::fromStdString(client->u->getInfo().getEsperienze_Professionali()));
         while (output->rowCount()!=0)
                output->removeRow(0);
         const vector<Username>& contacts=client->u->getRete()->getvector();
         for (vector<Username>::const_iterator it=contacts.begin();it!=contacts.end();it++)
         {vector<string> s=client->ricerca(it->getlogin());
          if (s.empty())
             {QErrorMessage * em=new QErrorMessage();
              em->showMessage("Utente non Trovato");}
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
              QTableWidgetItem *tipo_di_utente=new QTableWidgetItem ("Utente Business");
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
              QTableWidgetItem *tipo_di_utente=new QTableWidgetItem ("Utente Executive");
              QPushButton* visualizza_curriculum=new QPushButton("Curriculum");
              visualizza_curriculum->setStyleSheet("background:gray;min-height:25px;");
              connect(visualizza_curriculum,SIGNAL(clicked()),new Curriculum(client,s[6],s[7],s[8]),SLOT(show()));
              QPushButton* visualizza_rete=new QPushButton("Rete");
              visualizza_rete->setStyleSheet("background:gray;min-height:25px;");
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
}

void GestioneProfiloU::savedb(){
    client->savedb();
    QMessageBox msgBox;
    msgBox.setText("Salvataggio avvenuto con successo");
    msgBox.exec();
}

void GestioneProfiloU::showpassword(){
  if (show_password->checkState()==Qt::Checked)
   cpassword->setEchoMode(QLineEdit::Normal);
  else
   cpassword->setEchoMode(QLineEdit::Password);
}

void GestioneProfiloU::modifica_dati(){
   if (cnome->text()!=QString::fromStdString(client->u->getInfo().getNome()) || ccognome->text()!=QString::fromStdString(client->u->getInfo().getCognome()) || cdatadinascita->text()!=QString::fromStdString(client->u->getInfo().getData_di_Nascita()) || cluogodinascita->text()!=QString::fromStdString(client->u->getInfo().getLuogo_di_Nascita()) || clingue_conosciute->toPlainText()!=QString::fromStdString(client->u->getInfo().getLingue_conosciute()) || cformazione_scolastica->toPlainText()!=QString::fromStdString(client->u->getInfo().getFormazione_Scolastica()) || cesperienze_professionali->toPlainText()!=QString::fromStdString(client->u->getInfo().getEsperienze_Professionali()) || cusername->text()!=QString::fromStdString(client->u->getUsername().getlogin()) || cpassword->text()!=QString::fromStdString(client->u->getUsername().getpassword()) )
     {Info in(cnome->text().toStdString(),ccognome->text().toStdString(),cdatadinascita->text().toStdString(),cluogodinascita->text().toStdString(),clingue_conosciute->toPlainText().toStdString(),cformazione_scolastica->toPlainText().toStdString(),cesperienze_professionali->toPlainText().toStdString());
      Username un(cusername->text().toStdString(),cpassword->text().toStdString());
      Utente* u;
      if (dynamic_cast<UtenteBasic*>(client->u))
          u=new UtenteBasic(un,in);
      if (dynamic_cast<UtenteBusiness*>(client->u))
          u=new UtenteBusiness(un,in);
      if (dynamic_cast<UtenteExecutive*>(client->u))
          u=new UtenteExecutive(un,in);
      client->aggiornaProfilo(u);
      QMessageBox msgBox;
      msgBox.setText("Modifica avvenuta con successo");
      msgBox.exec();
   }
   else
     {QMessageBox msgBox;
      msgBox.setText("Modifica non avvenuta");
      msgBox.exec();}
}

