#include "QtNFCReaderGUI.h"




QtNFCReaderGUI::QtNFCReaderGUI(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}



void QtNFCReaderGUI::on_connect_clicked()
{
    uint16_t status = 0;
    //MonLecteur.Type=ReaderTCP;
    //strcpy(MonLecteur.IPReader,pszHost);
    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 0;
    status = OpenCOM(&MonLecteur);
    #if _DEBUG
        qDebug() << "OpenCOM1" << status;
    #endif
}
