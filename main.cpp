#include "mainwindow.h"
#include <QApplication>


//Main method that renders and shows the program
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
