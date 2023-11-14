#include "mainwindow.h"
#include "creatConnection.h"

#include <QApplication>
#include <QVariant>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include <QtDebug>

#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();
    return a.exec();
}
