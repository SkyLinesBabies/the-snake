#include "dialog.h"
#include "ui_dialog.h"

#include<QDialog>
#include<QPainter>
#include<QPaintEvent>
#include<QWidget>
#include<QMainWindow>
#include<QDialog>
#include<QMenu>
#include<QMessageBox>
#include<QMenuBar>
#include<QAction>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("The Snake"));
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    accept();
}
