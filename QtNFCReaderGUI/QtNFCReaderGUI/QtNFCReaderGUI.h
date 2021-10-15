#pragma once


#include <QtWidgets/QMainWindow>
#include "ui_QtNFCReaderGUI.h"
#include "lib/MfErrNo.h"
#include "lib/ODALID.h"
#if _DEBUG
#include <qdebug.h>
#endif



class QtNFCReaderGUI : public QMainWindow
{
    Q_OBJECT

public:
    QtNFCReaderGUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtNFCReaderGUIClass ui;
    ReaderName MonLecteur;
    //char pszHost[] = "192.168.1.4";


private slots:
    void on_connect_clicked();
};
