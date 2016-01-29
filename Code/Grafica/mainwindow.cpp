#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent){
    this->setStyleSheet("background:qlineargradient(x1:0 y1:0, x2:0 y2:1,stop:0  #3498db, stop:1 #2980b9); color:white; width:200px;" );
    this->setGeometry(500,250,0,0);
    QVBoxLayout*layout=new QVBoxLayout;
    QLabel* titolo=new QLabel("LinQedIn");
    titolo->setAlignment(Qt::AlignHCenter);
    titolo->setStyleSheet("font: 20pt \"FontAwesome\";" "font-weight:bold;" "background:transparent;" "margin-bottom:20px;" "margin-top:20px;" );

    QGroupBox *groupBoxUtente = new QGroupBox("Login Lato Client");
    groupBoxUtente->setStyleSheet("background:transparent;");
    groupBoxUtente->setAlignment(Qt::AlignHCenter);
    groupBoxUtente->setContentsMargins(5,0,5,0);
    QLabel* labelusernameU=new QLabel(tr("Username"));
    labelusernameU->setAlignment(Qt::AlignHCenter);
    labelusernameU->setStyleSheet("font: 12pt \"Times\";" "margin-top:20px;" "background:transparent;" );
    caselladitestoUserU=new QLineEdit();
    caselladitestoUserU->setStyleSheet("background:white;" "color:black;" );
    QLabel* labelPasswordU=new QLabel(tr("Password"));
    labelPasswordU->setAlignment(Qt::AlignHCenter);
    labelPasswordU->setStyleSheet("font: 12pt \"Times\";" "margin-top:0px;" "background:transparent;" );
    caselladitestoPwU=new QLineEdit();
    caselladitestoPwU->setStyleSheet("background:white;" "color:black;"  "margin-bottom:10px;");
    caselladitestoPwU->setEchoMode(QLineEdit::Password);
    QPushButton* accediU=new QPushButton("Accedi");
    accediU->setStyleSheet("background:#0082b6;");
    QVBoxLayout *vboxU = new QVBoxLayout;
    vboxU->addWidget(labelusernameU);
    vboxU->addWidget(caselladitestoUserU);
    vboxU->addWidget(labelPasswordU);
    vboxU->addWidget(caselladitestoPwU);
    vboxU->addWidget(accediU);
    groupBoxUtente->setLayout(vboxU);

    QGroupBox *groupBoxAdmin = new QGroupBox(tr("Login Lato Admin"));
    groupBoxAdmin->setStyleSheet("background:transparent;");
    QLabel* labelusernameA=new QLabel(tr("Username"));
    labelusernameA->setAlignment(Qt::AlignHCenter);
    labelusernameA->setStyleSheet("font: 12pt \"Times\";" "margin-top:20px;" "background:transparent;" );
    caselladitestoUserA=new QLineEdit();
    caselladitestoUserA->setStyleSheet("background:white;" "color:black;" );
    QLabel* labelPasswordA=new QLabel(tr("Password"));
    labelPasswordA->setAlignment(Qt::AlignHCenter);
    labelPasswordA->setStyleSheet("font: 12pt \"Times\";" "margin-top:0px;" "background:transparent;" );
    caselladitestoPwA=new QLineEdit();
    caselladitestoPwA->setStyleSheet("background:white;" "color:black;"  "margin-bottom:10px;");
    caselladitestoPwA->setEchoMode(QLineEdit::Password);
    QPushButton* accediA=new QPushButton(("Accedi"));
    accediA->setStyleSheet("background:#0082b6;");
    QVBoxLayout *vboxA = new QVBoxLayout;
          vboxA->addWidget(labelusernameA);
          vboxA->addWidget(caselladitestoUserA);
          vboxA->addWidget(labelPasswordA);
          vboxA->addWidget(caselladitestoPwA);
          vboxA->addWidget(accediA);
          groupBoxAdmin->setLayout(vboxA);

    QGridLayout *grid = new QGridLayout;

    grid->addWidget(groupBoxUtente, 0, 0);
    grid->addWidget(groupBoxAdmin, 0, 1);
    connect(accediU,SIGNAL(clicked()),this,SLOT(SlotAutenticationUser()));
    connect(accediA,SIGNAL(clicked()),this,SLOT(SlotAutenticationAdmin()));
    layout->addWidget(titolo);
    layout->addLayout(grid);
    layout -> setMargin(0);
    layout -> setContentsMargins (0,0,0,0);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}


void MainWindow::SlotAutenticationUser(){
   LinkedInClient* client=new LinkedInClient(Username(caselladitestoUserU->text().toStdString(),caselladitestoPwU->text().toStdString()));
    if (client->u!=0)
     {this->hide();
     AccessoUtente*au=new AccessoUtente(client,this);
     au->show();}
    else
    {QMessageBox * m=new QMessageBox();
     m->setText("Autenticazione non avvenuta");
     m->exec();}
}

void MainWindow::SlotAutenticationAdmin(){
   if (caselladitestoUserA->text()=="admin" && caselladitestoPwA->text().toStdString()=="admin")
    {this->hide();
    AccessoAdmin*ad=new AccessoAdmin(new LinQedInAdmin);
    ad->show();}
   else
    {QMessageBox * m=new QMessageBox();
     m->setText("Autenticazione non avvenuta");
     m->exec();}
}
