#include "QtNFCReaderGUI.h"



// constructor
QtNFCReaderGUI::QtNFCReaderGUI(QWidget* parent)
    : QMainWindow(parent)
{
    this->manager = new NFCManager(this);
    ui.setupUi(this);
    this->setScreen(CONNECT);
}



// called when the 'save' button is clicked
void QtNFCReaderGUI::on_save_clicked()
{
    if (this->manager->save(this->ui.first_name->text().toStdString(), this->ui.last_name->text().toStdString()))
        this->showAlertDialog("Saved", "Saved successfully");
    else
        this->showErrorDialog("Error", "Cannot save data to card");
}

// called when the 'load' button is clicked
void QtNFCReaderGUI::on_load_clicked()
{
    this->setScreen(LOADING);
    if (this->manager->load())
        this->updateUI();
    else
        this->showErrorDialog("Error", "Cannot load data from card");
    this->setScreen(DATA);
}

// called when the 'increment' button is clicked
void QtNFCReaderGUI::on_increment_clicked()
{
    this->setScreen(LOADING);
    if (this->manager->increment(this->ui.step_value->value()))
        this->updateUI();
    else
        this->showErrorDialog("Error", "Cannot increment counter value");
    this->setScreen(DATA);
}

// called when the 'decrement' button is clicked
void QtNFCReaderGUI::on_decrement_clicked()
{
    this->setScreen(LOADING);
    if (this->manager->decrement(this->ui.step_value->value()))
        this->updateUI();
    else
        this->showErrorDialog("Error", "Cannot increment counter value");
    this->setScreen(DATA);
}

// called when the 'connect' button is clicked
void QtNFCReaderGUI::on_connect_clicked()
{
    this->setScreen(LOADING);
    if (this->manager->connect())
    {
        this->on_load_clicked();
        this->setScreen(DATA);
    }
    else
    {
        this->showErrorDialog("Error", "Cannot connect to NFC reader");
        this->setScreen(CONNECT);
    }
}

// called when the 'disconnect' button is clicked
void QtNFCReaderGUI::on_disconnect_clicked()
{
    this->setScreen(CONNECT);
}



// changes the displayed layout based on the required screen to be displayed
void QtNFCReaderGUI::setScreen(QtNFCReaderGUI::Screen val)
{
    switch (val)
    {
    case CONNECT:
        this->ui.connect_layout->setVisible(true);
        this->ui.data_layout->setVisible(false);
        this->ui.loading_layout->setVisible(false);
        break;
    case DATA:
        this->ui.connect_layout->setVisible(false);
        this->ui.data_layout->setVisible(true);
        this->ui.loading_layout->setVisible(false);
        break;
    case LOADING:
        this->ui.connect_layout->setVisible(false);
        this->ui.data_layout->setVisible(false);
        this->ui.loading_layout->setVisible(true);
        break;
    }
}



// updates the component with the values stored by the NFC manager
void QtNFCReaderGUI::updateUI()
{
    this->ui.first_name->setText(QString::fromStdString(this->manager->getFirstName()));
    this->ui.last_name->setText(QString::fromStdString(this->manager->getLastName()));
    this->ui.counter_value->setText(QString::fromStdString(this->manager->getCounterValue()));
}



/*
* Functions to show dialogs
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