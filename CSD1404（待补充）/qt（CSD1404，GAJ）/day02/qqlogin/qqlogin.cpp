#include "qqlogin.h"		
QqLogin::QqLogin():ui(new Ui_Dialog()){
    ui->setupUi(this);
		connect(ui->blogin,SIGNAL(clicked()),
						this,SLOT(loginAndCancel()));
		connect(ui->bcancel,SIGNAL(clicked()),
						this,SLOT(loginAndCancel()));
}
QqLogin::~QqLogin(){
    delete ui;
}
		/* 负责登入 和 退出的槽函数 */
void   QqLogin::loginAndCancel(){
    /* 如何区分按钮 */
    if(sender()==ui->blogin){
		    qDebug("login clicked()");
		}
		if(sender()==ui->bcancel){
		    qDebug("cancel clicked()");
		}
}




