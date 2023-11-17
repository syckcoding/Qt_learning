#include "tableshow.h"
#include "ui_tableshow.h"
#include "creatConnection.h"

#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QMessageBox>

TableShow::TableShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableShow)
{
    ui->setupUi(this);

    if(!creatConnection()){
        QMessageBox::critical(0,"失败","You haven't open the database,please check again",QMessageBox::Ok);
        return ;
    }
    QMessageBox::information(0,"成功","You open the database successfully!",QMessageBox::Ok);

    showTable();
}

TableShow::~TableShow()
{
    delete ui;
}

void TableShow::showTable(){
    dbstu = QSqlDatabase::database("Students");
    QSqlQueryModel *stu_view = new QSqlQueryModel(ui->sqlView);
    stu_view->setQuery("select * from studentscore");

    stu_view->setHeaderData(0,Qt::Horizontal,tr("Name"));//设置表头
    stu_view->setHeaderData(1,Qt::Horizontal,tr("Id"));
    stu_view->setHeaderData(2,Qt::Horizontal,tr("Score"));

    ui->sqlView->setModel(stu_view);
}

void TableShow::on_pushButton_insert_clicked()
{
    QSqlQuery sq(dbstu);
    QString id = ui->lineEdit_id->text();
    QString name = ui->lineEdit_name->text();
    double score = ui->lineEdit_score->text().toDouble();

    if(id == ""){
        QMessageBox::critical(this,"失败","请输入学号",QMessageBox::Ok);
        return;
    }else if(name == ""){
        QMessageBox::critical(this,"失败","请输入姓名",QMessageBox::Ok);
        return;
    }else if(score < 0 || score > 100){
        QMessageBox::critical(this,"失败","请输入正确的成绩",QMessageBox::Ok);
        return;
    }

    QString s = QString("Insert into studentscore values('%1','%2',%3)").arg(id).arg(name).arg(score);

    if(sq.exec(s) == false){
        QMessageBox::critical(this,"失败","插入数据失败",QMessageBox::Ok);
        return;
    }else{
        QMessageBox::information(this,"成功","插入数据成功",QMessageBox::Ok);
    }

    showTable();
}


void TableShow::on_pushButton_delete_clicked()
{
    QSqlQuery sq(dbstu);
    QString id = ui->lineEdit_id->text();
    QString name = ui->lineEdit_name->text();
    double score = ui->lineEdit_score->text().toDouble();

    if(id == ""){
        QMessageBox::critical(this,"失败","请输入学号",QMessageBox::Ok);
        return;
    }else if(name == ""){
        QMessageBox::critical(this,"失败","请输入姓名",QMessageBox::Ok);
        return;
    }else if(score < 0 || score > 100){
        QMessageBox::critical(this,"失败","请输入正确的成绩",QMessageBox::Ok);
        return;
    }

    QString s = QString("Delete from studentscore where sid='%1' AND sname='%2' AND score=%3").arg(id).arg(name).arg(score);

    if(sq.exec(s) == false){
        QMessageBox::critical(this,"失败","删除数据失败",QMessageBox::Ok);
        return;
    }else{
        QMessageBox::information(this,"成功","删除数据成功",QMessageBox::Ok);
    }

    showTable();
}

