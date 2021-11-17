/*
* NFCReader - GUI
* ---------------
* 
* NFCReader - GUI is a Qt-based graphical user interface (GUI)
* to interface with a NFC reader. This application can :
*   - read data from a NFC tag
*   - save data to a NFC tag
*   - increment & decrement a counter
* See NFCManager class decscription for data layout.
*/





#include "QtNFCReaderGUI.h"
#include <QtWidgets/QApplication>



// main function, called on app start
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // the UI
    QtNFCReaderGUI w;           // the UI manager
    w.show();                   // show the UI
    return a.exec();            // execute the app
}