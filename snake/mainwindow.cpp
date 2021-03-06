#include "snake.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>

#include<QWidget>
#include<QMainWindow>
#include<QDialog>
#include<QMenu>
#include<QMessageBox>
#include<QMenuBar>
#include<QAction>
#include<QTime>
#include<QTimer>
#include<QPainter>
#include<QKeyEvent>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QUrl>



#include<QImage>
using namespace std;

MainWindow::MainWindow(QWidget * parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    setWindowTitle(tr("The Snake"));
    setFixedSize(1000,660);
    IsDie = false;
    bRun = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    times = 200;
    timer->start(times);
    t=new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(counter()));
    num=0;
    flag=0;
    flag1=0;
    QMediaPlayer *music=new QMediaPlayer;
    QMediaPlaylist*playlist=new QMediaPlaylist;
    playlist->addMedia(QUrl::fromLocalFile("D:/fbk/lib/SNAKE/snake/snake/2.mp3"));
    playlist->setCurrentIndex(1);
            music->setPlaylist(playlist);
            music->play();



}

MainWindow::~MainWindow()
{
}
void MainWindow::counter()
{
    num++;
    print();
}

void MainWindow::print()
{
    temp=QString::number(num,10);
    ui->lcdNumber->display(temp);
}
void MainWindow::timeout(void)
{
    if (bRun == false)
    {
        timer->stop();
        return;
    }
    snake.Move();
    IsDie = snake.IsDie();
    if (IsDie)
    {
        timer->stop();
        num=0;
        temp=QString::number(num,10);
        t->stop();
        bRun = false;
        QMessageBox::information(this, tr("游戏结束"),
                tr("啊哦~你输掉了！游戏结束！"));
        IsDie = false;
        snake.Clear();
        return;
    }
else
    update();
}

void MainWindow::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    QPixmap pix1;
    pix1.load(":/image/3.png");
    //painter.setBrush(Qt::white);
    painter.drawPixmap(0, 0, size().width(), size().height(),pix1);
    if (IsDie || !bRun)
    {
        return;
    }
    vector<Node> node;
    Node food;
    snake.OutputSnake(node, food);
    QPixmap pix;
    pix.load(":/image/R3.png");
    painter.drawPixmap(10*food.x, 10*food.y, 20, 20,pix);
    //画墙
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, 800, 10);  //上
    painter.drawRect(0, 650, 800, 10); //下
    painter.drawRect(0, 0, 10, 660); //左
    painter.drawRect(800, 0, 10, 660); //右
    //画蛇，蛇头跟蛇身用不同的颜色
    //蛇头

    QPixmap pix2;
    pix2.load(":/image/H1.png");
    painter.drawPixmap(10*node[0].x, 10*node[0].y, 20, 20,pix2);
    //painter.setBrush(Qt::yellow);
    //painter.drawEllipse(10*node[0].x, 10*node[0].y, 20, 20);

    //蛇身


    int n = node.size();
    QPixmap pix3;
    pix3.load(":/image/B2.png");
    for (int i = 1; i < n-1; i++)
    {
        painter.drawPixmap(10*node[i].x+2, 10*node[i].y+2, 16, 16,pix3);
    }
    painter.drawPixmap(10*node[n-1].x+3, 10*node[n-1].y+3, 14, 14,pix3);
    node.clear();
    QWidget::paintEvent(event);
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    int direct = 0;
    switch (event->key())
    {
    case Qt::Key_Up:
        direct = 1;
        break;
    case Qt::Key_Right:
        direct = 2;
        break;
    case Qt::Key_Down:
        direct = 3;
        break;
    case Qt::Key_Left:
        direct = 4;
        break;
    default:
        break;
    }
    snake.ChangeDirector(direct);
    QWidget::keyPressEvent(event);
    QMainWindow::keyPressEvent(event);
}


void MainWindow::startGame(void)
{
    bRun = true;
    timer->start(times);
     snake.AddNode(snake.SnakeNode[0].x,snake.SnakeNode[0].y);
      snake.AddNode(snake.SnakeNode[1].x,snake.SnakeNode[1].y);
}

void MainWindow::pauseGame(void)
{
    bRun = false;
    timer->stop();
}



void MainWindow::on_startgame_clicked()
{
     startGame();
     t->start(1000);
}

void MainWindow::on_pausegame_clicked()
{
     pauseGame();
     flag1++;
     if(flag1==1)t->stop();
     else
     {
         num=0;
         print();
         flag1=0;
     }
}


void MainWindow::on_exit_clicked()
{

        close();

}

void MainWindow::on_speedup_clicked()
{
    times -= 20;

        if (times <= 20)

        {

            times = 20;

        }

        timer->stop();

        timer->start(times);
}

void MainWindow::on_speeddown_clicked()
{
    times += 20;

           if (times >= 500)

           {

               times = 500;

           }

           timer->stop();

           timer->start(times);
}
