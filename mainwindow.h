#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tableshow.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_showButton_clicked();

private:
    Ui::MainWindow *ui;
    TableShow* t;
};
#endif // MAINWINDOW_H
