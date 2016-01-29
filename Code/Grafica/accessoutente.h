#ifndef ACCESSOUTENTE_H
#define ACCESSOUTENTE_H

#include "gestioneprofilou.h"
#include "gestionecontatti.h"



class AccessoUtente:public QWidget{
    Q_OBJECT
public:
   AccessoUtente(LinkedInClient*, QWidget* =0);

private:
   LinkedInClient* client;

public slots:
   void SLOTOpenAreaContatti();
   void SLOTOpenAreaProfilo();
   void SLOTLogout();
};

#endif // ACCESSOUTENTE_H
