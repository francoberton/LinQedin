#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "accessoutente.h"
#include "accessoadmin.h"
#include "../Logica/LinQedInClient.h"

class MainWindow:public QWidget{
     Q_OBJECT
public:
        MainWindow(QWidget* =0);

public slots:
        void SlotAutenticationUser();
        void SlotAutenticationAdmin();

private:
        QLineEdit* caselladitestoUserA;
        QLineEdit* caselladitestoPwA;
        QLineEdit* caselladitestoUserU;
        QLineEdit* caselladitestoPwU;


};

#endif // MAINWINDOW_H
