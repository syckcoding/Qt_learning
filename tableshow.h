#ifndef TABLESHOW_H
#define TABLESHOW_H

#include <QDialog>

namespace Ui {
class TableShow;
}

class TableShow : public QDialog
{
    Q_OBJECT

public:
    explicit TableShow(QWidget *parent = nullptr);
    ~TableShow();

private:
    Ui::TableShow *ui;
};

#endif // TABLESHOW_H
