#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setGeometry(0,0,1024,768);
    w.setWindowTitle("The Clinic");
    w.show();
    return a.exec();
}
