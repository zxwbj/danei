#include "yaojiang.h"
#include "ui_yaojiang.h"
#include <QPainter>
#include <QTime>
YaoJiang::YaoJiang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YaoJiang)
{
    qsrand(QTime::currentTime().
           msec());
    ui->setupUi(this);
    names[0]="shasha";
    names[1]="lili";
    names[2]="xinxin";
    names[3]="feifei";
    names[4]="jingjing";
    pflag=false;
    /* 创建定时器 对象 */
    timer=new QTimer();
    timer->setInterval(100);
    timer->start();
    /* 把timer  和 this 的 repaint*/
    connect(timer,SIGNAL(timeout()),
            this,SLOT(repaint()));
    connect(ui->bstart,SIGNAL(clicked()),
            this,SLOT(changePflag()));
    connect(ui->bstop,SIGNAL(clicked()),
            this,SLOT(changePflag()));

}
void   YaoJiang::paintEvent
    (QPaintEvent *e){
    QPainter   qp(this);
    //qp.drawLine(0,0,400,600);
    /* 加载图片 */
    if(pflag){
    QString  imgpath=":/img/";
    int  indnum=(qrand()%5)+1;
    imgpath=imgpath+
            QString::number(indnum);
    imgpath+=".jpg";
    img.load(imgpath);
    img=img.scaled(320,480);
    qp.drawImage(40,40,img);
    ui->pname->setText(
         names[indnum-1]);
    }
    /* 把要绘制的图片 画上去 */
    qp.drawImage(40,40,img);
}

void  YaoJiang::changePflag(){
    if(sender()==ui->bstart){
        pflag=true;
    }
    if(sender()==ui->bstop){
        pflag=false;
    }
}
YaoJiang::~YaoJiang()
{
    delete ui;
}
