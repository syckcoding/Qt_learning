#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creatConnection.h"
#include "tableshow.h"

#include <QApplication>
#include <QVariant>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include <QtDebug>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMovie *movie = new QMovie("C:/Users/86136/Desktop/Qttest/untitled/loading.gif");
    ui->giflabel->setMovie(movie);
    movie->start();
    t = new TableShow();
    t->setWindowTitle("学生成绩表");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(!creatConnection()){
        return ;
    }
    QSqlDatabase dbstu = QSqlDatabase::database("Students");
    QSqlQuery querystu(dbstu);

    querystu.exec("insert into studentscore values('1003','yyy',99)");

    querystu.exec("select sname from studentscore");

    while(querystu.next()){
        qDebug()<< querystu.value(0).toString();
        qDebug() << "enter!";
    }
}


void MainWindow::on_showButton_clicked()
{
    t->show();
}

