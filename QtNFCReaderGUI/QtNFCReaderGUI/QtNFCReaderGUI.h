#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtNFCReaderGUI.h"

#include "NFCManager.h"



class QtNFCReaderGUI : public QMainWindow
{
    Q_OBJECT

public:
    QtNFCReaderGUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtNFCReaderGUIClass ui;
    NFCManager* manager;

    // displayed screen management
    enum Screen {
        CONNECT,
        DATA,
        LOADING
    };
    void setScreen(QtNFCReaderGUI::Screen val);

    void updateUI();

    // these functions shows various dialogs
    void showErrorDialog(std::string title, std::string msg);
    void showAlertDialog(std::string title, std::string msg);


private slots:
    void on_connect_clicked();
    void on_save_clicked();
    void on_load_clicked();
    void on_increment_clicked();
    void on_decrement_clicked();
    void on_disconnect_clicked();
};
