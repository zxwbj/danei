#include "adder.h"		
Adder::Adder(){
		/* 创建一个界面对象 */
    ui=new Ui_Dialog();
		/* 加载界面 */
		ui->setupUi(this);
		/* 访问界面中的数据使用ui 即可 */
		connect(ui->equ,SIGNAL(clicked()),
						this,SLOT(getCompRes()));
}
Adder::~Adder(){
    delete ui;
}
void  Adder::getCompRes(){
    ui->res->setText(QString::number(
			  ui->add->text().toInt()+
				ui->added->text().toInt()));
}


