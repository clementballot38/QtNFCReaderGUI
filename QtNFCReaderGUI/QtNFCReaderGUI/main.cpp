#include "QtNFCReaderGUI.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtNFCReaderGUI w;
    w.show();
    return a.exec();
}