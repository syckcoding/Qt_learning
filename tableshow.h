#ifndef TABLESHOW_H
#define TABLESHOW_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class TableShow;
}

class TableShow : public QDialog
{
    Q_OBJECT

public:
    explicit TableShow(QWidget *parent = nullptr);
    ~TableShow();

private slots:
    void on_pushButton_insert_clicked();
    void showTable();

private:
    Ui::TableShow *ui;
    QSqlDatabase dbstu;
};

#endif // TABLESHOW_H
