#include "registrazione.h"

#include<iostream>
#include<string>
#include<QDebug>
using std::string;
    Registrazione::Registrazione(LinQedInAdmin* a,QWidget *parent):admin(a){
        this->setStyleSheet("background: #0082b6;" "color:white;" );
        this->setGeometry(500,20,0,0);
        QVBoxLayout*layout=new QVBoxLayout;
        QLabel* iscriviti=new QLabel("Registra Utente");
        iscriviti->setAlignment(Qt::AlignHCenter);
        iscriviti->setStyleSheet("font: 20pt \"FontAwesome\";" "font-weight:bold;"  "margin-bottom:20px;" "margin-top:20px;" );


        QVBoxLayout *contenitore = new QVBoxLayout;
        QLabel* nome=new QLabel("*Nome:");
        QLabel* cognome=new QLabel("*Cognome:");
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
        QLabel* username=new QLabel("*Username:");
        QLabel* password=new QLabel("*Password:");
        cnome=new QLineEdit();
        cnome->setStyleSheet("background:white; color:black;max-width:200px;");
        ccognome=new QLineEdit();
        ccognome->setStyleSheet("background:white;color:black;max-width:200px;" );
        cdatadinascita=new QDateEdit();
        cdatadinascita->setStyleSheet("background:white;color:black; min-width:180px;" );
        cdatadinascita->setDisplayFormat("dd-MM-yyyy");
        cluogodinascita=new QLineEdit();
        cluogodinascita->setStyleSheet("background:white; color:black;max-width:200px;" );
        clingue_conosciute=new QTextEdit();
        clingue_conosciute->setStyleSheet("background:white;color:black;max-height:50px;max-width:200px;" );
        cformazione_scolastica=new QTextEdit();
        cformazione_scolastica->setStyleSheet("background:white;color:black;max-height:70px;max-width:200px;" );
        cesperienze_professionali=new QTextEdit();
        cesperienze_professionali->setStyleSheet("background:white;color:black;max-height:70px;max-width:200px;" );
        cusername=new QLineEdit();
        cusername->setStyleSheet("background:white;color:black;max-width:200px;" );
        cpassword=new QLineEdit();
        cpassword->setStyleSheet("background:white;color:black;max-width:200px;" );
        cpassword->setEchoMode(QLineEdit::Password);
        show_password=new QCheckBox("Show password", this);
        show_password->setStyleSheet("padding-left:95px;" );
        connect(show_password,SIGNAL(stateChanged(int)),this,SLOT(ShowPassword()));
        QHBoxLayout* BoxNome=new QHBoxLayout;
        QHBoxLayout* BoxCognome=new QHBoxLayout;
        QHBoxLayout* BoxDatadiNascita=new QHBoxLayout;
        QHBoxLayout* BoxLuogodiNascita=new QHBoxLayout;
        QHBoxLayout* BoxLingueConosciute=new QHBoxLayout;
        QHBoxLayout* BoxFormazione_Scolastica=new QHBoxLayout;
        QHBoxLayout* BoxEsperienze_Professionali=new QHBoxLayout;
        QHBoxLayout* BoxUsername=new QHBoxLayout;
        QHBoxLayout* BoxPassword=new QHBoxLayout;
        QHBoxLayout* BoxShowPassword=new QHBoxLayout;
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
        BoxShowPassword->addWidget(show_password);

        contenitore->addLayout(BoxNome);
        contenitore->addLayout(BoxCognome);
        contenitore->addLayout(BoxDatadiNascita);
        contenitore->addLayout(BoxLuogodiNascita);
        contenitore->addLayout(BoxLingueConosciute);
        contenitore->addLayout(BoxFormazione_Scolastica);
        contenitore->addLayout(BoxEsperienze_Professionali);
        contenitore->addLayout(BoxUsername);
        contenitore->addLayout(BoxPassword);
        contenitore->addLayout(BoxShowPassword);
        QGroupBox  * BoxDatiUtente =  new QGroupBox ( "Dati Anagrafici" );
        BoxDatiUtente ->setLayout(contenitore);

        QGroupBox  * BoxSelezioneUtente =  new QGroupBox ( "Selezione Tipo Utente" );
        utente_basic=new QRadioButton("Utente Basic");
        utente_business=new QRadioButton("Utente Business");
        utente_executive=new QRadioButton("Utente Executive");
        utente_basic->setChecked(true);
        QVBoxLayout  * vbox =  new QVBoxLayout;
        vbox -> addWidget(utente_basic);
        vbox -> addWidget(utente_business);
        vbox -> addWidget(utente_executive);
        BoxSelezioneUtente -> setLayout (vbox);

        QPushButton* pulsante=new QPushButton("Registra");
        connect(pulsante,SIGNAL(clicked()),this,SLOT(Registra()));
        layout->addWidget(iscriviti);
        layout->addWidget(BoxDatiUtente);
        layout->addWidget(BoxSelezioneUtente);
        layout->addWidget(pulsante);
        layout -> setMargin(0);
        layout -> setContentsMargins (0,0,0,0);
        layout->setSizeConstraint(QLayout::SetFixedSize);
        setLayout(layout);
    }

    void Registrazione::ShowPassword(){
      if (show_password->checkState()==Qt::Checked)
       cpassword->setEchoMode(QLineEdit::Normal);
      else
       cpassword->setEchoMode(QLineEdit::Password);
    }


    string Registrazione::gettipoutente(){
      if (utente_basic->isChecked())
        return utente_basic->text().toStdString();
      if (utente_business->isChecked())
        return utente_business->text().toStdString();
      return utente_executive->text().toStdString();
    }

   void Registrazione::Registra(){
    Utente* u=admin->find(cusername->text().toStdString());
    if (!u)
     if ( !cnome->text().isEmpty() && !ccognome->text().isEmpty() && !cusername->text().isEmpty() && !cpassword->text().isEmpty())
     {string tdu=gettipoutente();
      Info in(cnome->text().toStdString(),ccognome->text().toStdString(),cdatadinascita->text().toStdString(),cluogodinascita->text().toStdString(),clingue_conosciute->toPlainText().toStdString(),cformazione_scolastica->toPlainText().toStdString(),cesperienze_professionali->toPlainText().toStdString());
      if (tdu=="Utente Basic")
       u=new UtenteBasic(Username(cusername->text().toStdString(),cpassword->text().toStdString()),in);
      if (tdu=="Utente Business")
       u=new UtenteBusiness(Username(cusername->text().toStdString(),cpassword->text().toStdString()),in);
      if (tdu=="Utente Executive")
       u=new UtenteExecutive(Username(cusername->text().toStdString(),cpassword->text().toStdString()),in);
      admin->insert(u);
      this->close();
      QMessageBox * m=new QMessageBox();
      m->setText("Utente registrato correttamente");
      m->exec(); }
     else
      {QMessageBox * m=new QMessageBox();
       m->setText("Campi constrassegnati con asterisco mancanti!");
       m->exec();}
    else
       {QMessageBox * m=new QMessageBox();
        m->setText("Username già presente");
        m->exec();}
    }
