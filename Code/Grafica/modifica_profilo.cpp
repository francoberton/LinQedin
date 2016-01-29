#include "modifica_profilo.h"

Modifica_Profilo::Modifica_Profilo(LinkedInClient* c,QWidget *parent):client(c){
 this->setStyleSheet("background: #0082b6;" "color:white;" );
 this->setGeometry(500,100,0,0);
 QVBoxLayout*layout=new QVBoxLayout;
 QLabel* iscriviti=new QLabel("Modifica Dati");
 iscriviti->setAlignment(Qt::AlignHCenter);
 iscriviti->setStyleSheet("font: 20pt \"FontAwesome\";" "font-weight:bold;"  "margin-bottom:20px;" "margin-top:20px;" );

 QVBoxLayout *contenitore = new QVBoxLayout;
 QLabel* nome=new QLabel("Nome:");
 QLabel* cognome=new QLabel("Cognome:");
 QLabel* datadinascita=new QLabel("Data  di Nascita:");
 datadinascita->setWordWrap(1);
 datadinascita->setStyleSheet("max-width:120px");
 QLabel* luogodinascita=new QLabel("Luogo di Nascita:");
 luogodinascita->setWordWrap(1);
 luogodinascita->setStyleSheet("max-width:120px");
 QLabel* lingue_conosciute=new QLabel("Lingue conosciute:");
 lingue_conosciute->setWordWrap(1);
 lingue_conosciute->setStyleSheet("max-width:120px");
 QLabel* formazione_scolastica=new QLabel("Formazione Scolastica:");
 formazione_scolastica->setWordWrap(1);
 formazione_scolastica->setStyleSheet("max-width:120px");
 QLabel* esperienze_professionali=new QLabel ("Esperienze professionali:");
 esperienze_professionali->setWordWrap(1);
 esperienze_professionali->setStyleSheet("max-width:120px");
 QLabel* username=new QLabel("Username:");
 QLabel* password=new QLabel("Password:");
 cnome=new QLineEdit();
 cnome->setStyleSheet("background:white; color:black;max-width:200px;");
 ccognome=new QLineEdit();
 ccognome->setStyleSheet("background:white;color:black;max-width:200px;" );
 cdatadinascita=new QLineEdit();
 cdatadinascita->setStyleSheet("background:white;color:black; max-width:200px;" );
 cluogodinascita=new QLineEdit();
 cluogodinascita->setStyleSheet("background:white; color:black;max-width:200px;" );
 clingue_conosciute=new QTextEdit();
 clingue_conosciute->setStyleSheet("background:white;color:black;max-height:50px;max-width:200px;" );
 cformazione_scolastica=new QTextEdit();
 cformazione_scolastica->setStyleSheet("background:white;color:black;max-height:80px;max-width:200px;" );
 cesperienze_professionali=new QTextEdit();
 cesperienze_professionali->setStyleSheet("background:white;color:black;max-height:80px;max-width:200px;" );
 cusername=new QLineEdit();
 cusername->setStyleSheet("background:white;color:black;max-width:200px;" );
 cpassword=new QLineEdit();
 cpassword->setStyleSheet("background:white;color:black;max-width:200px;" );
 cpassword->setEchoMode(QLineEdit::Password);
 show_password=new QCheckBox("Show password", this);
 show_password->setStyleSheet("padding-left:95px;" );
 connect(show_password,SIGNAL(stateChanged(int)),this,SLOT(showpassword()));
 QHBoxLayout* BoxNome=new QHBoxLayout;
 QHBoxLayout* BoxCognome=new QHBoxLayout;
 QHBoxLayout* BoxDatadiNascita=new QHBoxLayout;
 QHBoxLayout* BoxLuogodiNascita=new QHBoxLayout;
 QHBoxLayout* BoxLingueConosciute=new QHBoxLayout;
 QHBoxLayout* BoxFormazione_Scolastica=new QHBoxLayout;
 QHBoxLayout* BoxEsperienze_Professionali=new QHBoxLayout;
 QHBoxLayout* BoxUsername=new QHBoxLayout;
 QHBoxLayout* BoxPassword=new QHBoxLayout;
 QHBoxLayout* BoxShow_Password=new QHBoxLayout;
 BoxNome->addWidget(nome);
 BoxNome->addWidget(cnome);
 BoxCognome->addWidget(cognome);
 BoxCognome->addWidget(ccognome);
 BoxDatadiNascita->addWidget(datadinascita);
 BoxDatadiNascita->addWidget(cdatadinascita);
 BoxLuogodiNascita->addWidget(luogodinascita);
 BoxLuogodiNascita->addWidget(cluogodinascita);
 BoxLingueConosciute->addWidget(lingue_conosciute);
 BoxLingueConosciute->addWidget(clingue_conosciute);
 BoxFormazione_Scolastica->addWidget(formazione_scolastica);
 BoxFormazione_Scolastica->addWidget(cformazione_scolastica);
 BoxEsperienze_Professionali->addWidget(esperienze_professionali);
 BoxEsperienze_Professionali->addWidget(cesperienze_professionali);
 BoxUsername->addWidget(username);
 BoxUsername->addWidget(cusername);
 BoxPassword->addWidget(password);
 BoxPassword->addWidget(cpassword);
 BoxShow_Password->addWidget(show_password);

 contenitore->addLayout(BoxNome);
 contenitore->addLayout(BoxCognome);
 contenitore->addLayout(BoxDatadiNascita);
 contenitore->addLayout(BoxLuogodiNascita);
 contenitore->addLayout(BoxLingueConosciute);
 contenitore->addLayout(BoxFormazione_Scolastica);
 contenitore->addLayout(BoxEsperienze_Professionali);
 contenitore->addLayout(BoxUsername);
 contenitore->addLayout(BoxPassword);
 contenitore->addLayout(BoxShow_Password);
 QGroupBox  * BoxDatiUtente =  new QGroupBox ( "Dati Anagrafici" );
 BoxDatiUtente ->setLayout(contenitore);

 QPushButton* pulsante=new QPushButton("Conferma");
 connect(pulsante,SIGNAL(clicked()),this,SLOT(modifica_dati()));
 layout->addWidget(iscriviti);
 layout->addWidget(BoxDatiUtente);
 layout->addWidget(pulsante);

 layout->setSizeConstraint(QLayout::SetFixedSize);
 setLayout(layout);
 compilacaselle();
}

 void Modifica_Profilo::showpassword(){
   if (show_password->checkState()==Qt::Checked)
    cpassword->setEchoMode(QLineEdit::Normal);
   else
    cpassword->setEchoMode(QLineEdit::Password);
 }

 void Modifica_Profilo::compilacaselle(){
     cnome->setText(QString::fromStdString(client->u->getInfo().getNome()));
     ccognome->setText(QString::fromStdString(client->u->getInfo().getCognome()));
     cdatadinascita->setText(QString::fromStdString(client->u->getInfo().getData_di_Nascita()));
     cluogodinascita->setText(QString::fromStdString(client->u->getInfo().getLuogo_di_Nascita()));
     clingue_conosciute->setText(QString::fromStdString(client->u->getInfo().getLingue_conosciute()));
     cformazione_scolastica->setText(QString::fromStdString(client->u->getInfo().getFormazione_Scolastica()));
     cesperienze_professionali->setText(QString::fromStdString(client->u->getInfo().getEsperienze_Professionali()));
     cusername->setText(QString::fromStdString(client->u->getUsername().getlogin()));
     cpassword->setText(QString::fromStdString(client->u->getUsername().getpassword()));
 }

 void Modifica_Profilo::modifica_dati(){
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
       std::cerr << "Modifica avvenuta con successo:" << std::endl;
    }
 }
