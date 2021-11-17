/*
* QtNFCReaderGUI
* --------------
* 
* This class is the main class of this project. It handles the UI :
* component values, dialogs & buttons events.
*/




#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtNFCReaderGUI.h"

#include "NFCManager.h"



class QtNFCReaderGUI : public QMainWindow
{
    Q_OBJECT

public:
    // class constructor
    QtNFCReaderGUI(QWidget *parent = Q_NULLPTR);

private:
    // UI reference
    Ui::QtNFCReaderGUIClass ui;
    // NFC manager
    NFCManager* manager;

    // available screens
    enum Screen {
        CONNECT,
        DATA,
        LOADING
    };
    void setScreen(QtNFCReaderGUI::Screen val);

    // update all components
    void updateUI();

    // these functions shows various dialogs
    void showErrorDialog(std::string title, std::string msg);
    void showAlertDialog(std::string title, std::string msg);


private slots:
    // slots to handle buttons events
    void on_connect_clicked();
    void on_save_clicked();
    void on_load_clicked();
    void on_increment_clicked();
    void on_decrement_clicked();
    void on_disconnect_clicked();
};
