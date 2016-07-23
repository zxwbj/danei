#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void   Dialog::mousePressEvent
    (QMouseEvent *e){
    switch(e->buttons()){
        case Qt::LeftButton:
        qDebug("left clicked %d:%d",
               e->x(),e->y());
        break;
        case Qt::RightButton:
        qDebug("right clicked");
        break;
        case Qt::MidButton:
        qDebug("mid clicked");
        break;
    }
}

void  Dialog::keyPressEvent
(QKeyEvent *e){
    switch(e->key()){
        case  Qt::Key_Up:
        qDebug("up key pressed");
        break;
        case  Qt::Key_Down:
        qDebug("down key pressed");
        break;
        case  Qt::Key_Left:
        qDebug("left key pressed");
        break;
        case  Qt::Key_Right:
        qDebug("right key pressed");
        break;
    }
}








