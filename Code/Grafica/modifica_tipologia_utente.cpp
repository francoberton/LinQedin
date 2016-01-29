#include "modifica_tipologia_utente.h"


Modifica_Tipologia_Utente::Modifica_Tipologia_Utente(LinQedInAdmin* l,string user,QWidget* parent):admin(l),login(user)
{  this->setStyleSheet("background:qlineargradient(x1:0 y1:0, x2:0 y2:1,stop:0  #3498db, stop:1 #2980b9);color:white;" );
    this->setGeometry(500,200,0,0);
    QVBoxLayout*layout=new QVBoxLayout;
    QLabel* lmodifica=new QLabel("Modifica Tipologia Utente");
    lmodifica->setAlignment(Qt::AlignHCenter);
    lmodifica->setStyleSheet("font: 20pt \"FontAwesome\"; font-weight:bold; background:transparent; margin-bottom:20px; margin-top:20px;" );

    QGroupBox  * BoxSelezioneUtente =  new QGroupBox ( "Selezione Tipo Utente" );
    BoxSelezioneUtente->setStyleSheet("background:transparent;");
    utente_basic=new QRadioButton("Utente Basic");
    utente_business=new QRadioButton("Utente Business");
    utente_executive=new QRadioButton("Utente Executive");
    QVBoxLayout  * vbox =  new QVBoxLayout;
    vbox -> addWidget(utente_basic);
    vbox -> addWidget(utente_business);
    vbox -> addWidget(utente_executive);
    BoxSelezioneUtente -> setLayout (vbox);
    QPushButton * modifica=new QPushButton("Modifica");
    connect(modifica,SIGNAL(clicked()),this,SLOT(modifica_tipo_utente()));
    modifica->setStyleSheet("background:#0082b6;");
    layout->addWidget(lmodifica);
    layout->addWidget(BoxSelezioneUtente);
    layout->addWidget(modifica);
    layout -> setMargin(0);
    layout -> setContentsMargins (0,0,0,0);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}

void Modifica_Tipologia_Utente::gettipologiaUtente(const string & tdu){
    Tipo_Utente_init=tdu;
    if (tdu=="Utente Basic")
       utente_basic->setChecked(true);
    if (tdu=="Utente Business")
       utente_business->setChecked(true);
    if (tdu=="Utente Executive")
       utente_executive->setChecked(true);
}


void Modifica_Tipologia_Utente::modifica_tipo_utente(){
    std::string tdu;
    if (utente_basic->isChecked())
        tdu=utente_basic->text().toStdString();
    if (utente_business->isChecked())
        tdu=utente_business->text().toStdString();
    if (utente_executive->isChecked())
        tdu=utente_executive->text().toStdString();
    if (tdu!= Tipo_Utente_init )
        {admin->changeSubscriptionType(login,tdu);
        this->close();
        QMessageBox msgBox;
        msgBox.setText("Modifica avvenuta con successo");
        msgBox.exec();}
    else
        {QMessageBox msgBox;
        msgBox.setText("Modifica non avvenuta");
        msgBox.exec();}

}
