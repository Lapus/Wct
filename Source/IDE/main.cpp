#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QLocale>

// Оставь надежду, всяк сюда входящий.

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //QObject::connect(&actionexit, SIGNAL(clicked()), qApp, SLOT(quit()));
    return a.exec();
}



