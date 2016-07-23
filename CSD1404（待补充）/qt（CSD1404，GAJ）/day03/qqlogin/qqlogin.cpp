#include "qqlogin.h"
#include "ui_qqlogin.h"

QqLogin::QqLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QqLogin)
{
    ui->setupUi(this);
    connect(ui->blogin,
            SIGNAL(clicked()),
            this,
            SLOT(loginAndCancel()));
    connect(ui->bcancel,
            SIGNAL(clicked()),
            this,
            SLOT(loginAndCancel()));
}

QqLogin::~QqLogin()
{
    delete ui;
}
#include <QMessageBox>
void   QqLogin::loginAndCancel(){
    if(sender()==ui->blogin){
        if(ui->uname->text()=="abc"
        && ui->upasswd->text()=="123"){
        QMessageBox   msg(this);
        msg.setText("login success!");
        msg.exec();
        }else{
        QMessageBox   msg(this);
        msg.setText("login failed");
        msg.exec();
        }
     }
    if(ui->bcancel==sender()){
        QMessageBox  msg(this);
        msg.setText("are you quit?");
        msg.setStandardButtons(
           QMessageBox::Yes|
           QMessageBox::No);
        if(msg.exec()==
                QMessageBox::Yes){
           this->close();
        }
    }
}
