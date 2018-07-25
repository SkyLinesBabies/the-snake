#include "mainwindow.h"
#include"dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog dialog;
    if(dialog.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }

    return a.exec();
}
