#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QKeyEvent>
#include<snake.h>
#include<QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget * parent = 0);
    ~MainWindow(void);
    void print();

protected slots:
    void timeout(void);   //自定义的槽函数，处理定时器时间，用于游戏更新
    void startGame(void); //自定义的槽函数，开始游戏
    void pauseGame(void); //自定义的槽函数，暂停游戏

public:
    void keyPressEvent(QKeyEvent * event); //处理按键消息
    void paintEvent(QPaintEvent * event); //处理重绘消息

private slots:

    void on_startgame_clicked();

    void on_pausegame_clicked();

    void on_exit_clicked();

    void on_speedup_clicked();

    void on_speeddown_clicked();

private:
    Ui::MainWindow *ui;
    int num;
    QTimer *t;
    int flag1;
    int flag;//计时
    QString temp;
private:
    Snake snake; //贪食蛇的类
    bool IsDie;  //游戏是否结束
    bool bRun;  //游戏是否运行的变量
    QTimer * timer; //游戏定时器
    int times; //定时器的频率
public slots:
    void counter();//计时
};
#endif // MAINWINDOW_H
