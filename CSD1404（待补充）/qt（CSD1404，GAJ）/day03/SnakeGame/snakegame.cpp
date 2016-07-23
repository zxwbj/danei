#include "snakegame.h"
#include <QMessageBox>
SnakeGame::SnakeGame(){
    qsrand(QTime::currentTime().
          msec());
    this->resize(800,600);
    footLen=40;
    snake.push_back(getFood());
    food=getFood();
    timer=new QTimer();
    timer->setInterval(300);
    timer->start();
    dire=D_RIGHT;
    score=0;
    /* timer  this */
    connect(timer,SIGNAL(timeout()),
            this,SLOT(snakeMove()));
}
SnakeGame::~SnakeGame(){

}
/* 根据方向移动 */
void  SnakeGame::snakeMove(){
    /* 蛇头原来的坐标 */
    int  sx=snake[0]->x();
    int  sy=snake[0]->y();
    /* 蛇头和食物重合 */
    if(sx==food->x() &&
       sy==food->y()){
       snake.push_back(food);
       food=getFood();
       score++;
    }
    /* 如何把后一个 移动到前一个元素上 */
    for(int i=snake.size()-1;i>0;i--){
        snake[i]->move(
        snake[i-1]->x(),snake[i-1]->y());
    }
    if(5==score){
        QMessageBox  msg;
        msg.setText("are you quit?");
        msg.setStandardButtons(
           QMessageBox::Yes|
            QMessageBox::No);
        if(msg.exec()==QMessageBox::Yes){
            this->close();
        }else{
            score++;
        }
    }
    if(sx<0){
       QMessageBox  msg;
       msg.setText("game over!");
       msg.exec();
       this->close();
    }
    switch(dire){
        case D_UP:
        sy=sy-footLen;
        break;
        case D_DOWN:
        sy=sy+footLen;
        break;
        case D_LEFT:
        sx=sx-footLen;
        break;
        case D_RIGHT:
        sx=sx+footLen;
        break;
    }
    /* 把蛇头移动到新坐标 */
    snake[0]->move(sx,sy);
}
void  SnakeGame::keyPressEvent
(QKeyEvent *e){
    switch(e->key()){
        case Qt::Key_Up:
        dire=D_UP;
        break;
        case  Qt::Key_Down:
        dire=D_DOWN;
        break;
        case Qt::Key_Left:
        dire=D_LEFT;
        break;
        case Qt::Key_Right:
        dire=D_RIGHT;
        break;
    }
}
QLabel*  SnakeGame::getFood(){
    food=new QLabel(this);
    food->resize(footLen,footLen);
    food->setAutoFillBackground(true);
    /* 颜色随即 */
    food->setPalette(QPalette
        (QColor(qrand()%256,
                qrand()%256,
                qrand()%256)));
    /* 位置随机
       界面范围内
       footLen 的整数倍 */
    int  w=this->width()-footLen;
    int  h=this->height()-footLen;
    food->move(((qrand()%w)/footLen)
               *footLen,
               ((qrand()%h)/footLen)
                           *footLen);
    food->show();
    return food;
}






