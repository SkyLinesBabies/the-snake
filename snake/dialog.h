
#define DIALOG_H


#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QDialog>
#include "snake.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;


};

#endif // DIALOG_H
