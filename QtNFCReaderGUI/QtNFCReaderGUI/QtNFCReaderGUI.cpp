#include "QtNFCReaderGUI.h"




QtNFCReaderGUI::QtNFCReaderGUI(QWidget* parent)
    : QMainWindow(parent)
{
    this->manager = new NFCManager(this);
    ui.setupUi(this);
    this->setScreen(CONNECT);
}



void QtNFCReaderGUI::on_connect_clicked()
{
   if (this->manager->connect())
        this->setScreen(DATA);
    else
        this->showErrorDialog("Error", "Cannot connect to NFC reader");
}

void QtNFCReaderGUI::on_disconnect_clicked()
{
    this->setScreen(CONNECT);
}



void QtNFCReaderGUI::setScreen(QtNFCReaderGUI::Screen val)
{
    switch (val)
    {
    case CONNECT:
        this->ui.connect_layout->setVisible(true);
        this->ui.data_layout->setVisible(false);
        break;
    case DATA:
        this->ui.connect_layout->setVisible(false);
        this->ui.data_layout->setVisible(true);
        break;
    }
}



/*
* Utilities functions to show dialogs
*/
void QtNFCReaderGUI::showErrorDialog(std::string title, std::string msg)
{
    QMessageBox box;
    box.critical(this, QString::fromStdString(title), QString::fromStdString(msg), QMessageBox::StandardButton::Close);
}

void QtNFCReaderGUI::showAlertDialog(std::string title, std::string msg)
{
    QMessageBox box;
    box.information(this, QString::fromStdString(title), QString::fromStdString(msg), QMessageBox::StandardButton::Close);
}