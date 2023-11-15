#include "tableshow.h"
#include "ui_tableshow.h"
#include "creatConnection.h"

#include <QSqlTableModel>
#include <QSqlQueryModel>

TableShow::TableShow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableShow)
{
    ui->setupUi(this);

    if(!creatConnection()){
        return ;
    }
    QSqlDatabase dbstu = QSqlDatabase::database("Students");
    QSqlQueryModel *stu_view = new QSqlQueryModel(ui->sqlView);
    stu_view->setQuery("select * from studentscore");

    stu_view->setHeaderData(0,Qt::Horizontal,tr("Name"));//设置表头
    stu_view->setHeaderData(1,Qt::Horizontal,tr("Id"));
    stu_view->setHeaderData(2,Qt::Horizontal,tr("Score"));

    ui->sqlView->setModel(stu_view);
}

TableShow::~TableShow()
{
    delete ui;
}
