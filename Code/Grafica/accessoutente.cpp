#include "accessoutente.h"

AccessoUtente::AccessoUtente(LinkedInClient* c,QWidget* parent):client(c){
    this->setStyleSheet("background:qlineargradient(x1:0 y1:0, x2:0 y2:1,stop:0  #3498db, stop:1 #2980b9);color:white;min-width:350px;min-height:50px;" );
    this->setGeometry(500,250,0,0);

    QVBoxLayout* layout=new QVBoxLayout;
    QLabel* menu=new QLabel("Menu");
    menu->setAlignment(Qt::AlignHCenter);
    menu->setStyleSheet("font: 20pt \"FontAwesome\";" "font-weight:bold;" "background:transparent;" "margin-bottom:20px;" "margin-top:20px;" );
    QPushButton* contatti=new QPushButton("Gestione Contatti");
    contatti->setStyleSheet("margin-right:50px;margin-left:50px;background: #0082b6; ");
    connect(contatti,SIGNAL(clicked()),this,SLOT(SLOTOpenAreaContatti()));
    QPushButton* profilo=new QPushButton("Gestione Profilo");
    profilo->setStyleSheet("margin-right:50px;margin-left:50px;background: #0082b6");
    connect(profilo,SIGNAL(clicked()),this,SLOT(SLOTOpenAreaProfilo()));
    QPushButton* logout=new QPushButton("Logout");
    logout->setStyleSheet("margin-right:50px;margin-left:50px;background: #0082b6");
    connect(logout,SIGNAL(clicked()),this,SLOT(SLOTLogout()));
    layout->addWidget(menu);
    layout->addWidget(contatti);
    layout->addWidget(profilo);
    layout->addWidget(logout);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}

void AccessoUtente::SLOTOpenAreaContatti()
{
    this->hide();
    GestioneContatti* gc=new GestioneContatti(client,this);
    gc->show();
}

void AccessoUtente::SLOTOpenAreaProfilo()
{
    this->hide();
    GestioneProfiloU* gp=new GestioneProfiloU(client,this);
    gp->visualizzaprofilo();
    gp->show();
}

void AccessoUtente::SLOTLogout()
{
    this->close();
    MainWindow* MW=new MainWindow();
    MW->show();
}


