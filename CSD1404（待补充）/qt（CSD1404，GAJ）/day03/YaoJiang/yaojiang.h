#ifndef YAOJIANG_H
#define YAOJIANG_H

#include <QDialog>
#include <QImage>
#include <QTimer>
namespace Ui {
class YaoJiang;
}

class YaoJiang : public QDialog
{
    Q_OBJECT
    
public:
    explicit YaoJiang(QWidget *parent = 0);
    ~YaoJiang();
    
private:
    Ui::YaoJiang *ui;
    /* 要绘制的图片 */
    QImage    img;
    /* 控制定时的绘制 */
    QTimer    *timer;
    /*  参与摇奖的人的数组 */
    QString   names[5];
    /* 控制绘制的标志 */
    bool      pflag;
/* 绘制事件处理函数 */
public:
void   paintEvent(QPaintEvent *e);
/* 增加改变绘制标志的 槽函数 */
public  slots:
void  changePflag();

};
#endif // YAOJIANG_H




