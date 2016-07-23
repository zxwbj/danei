#include "adder.h"		 
Adder::Adder(){
    this->resize(650,300);
    /* 给指针成员赋值 */
    add=new QLineEdit(this);
    oper=new QLabel("+",this);
    added=new QLineEdit(this);
    equ=new QPushButton("=",this);
    res=new QLineEdit(this);
    /* 调整组件位置 */
    add->move(20,130);
    oper->move(170,130);
    added->move(220,130);
    equ->move(360,130);
    res->move(470,130);
		/* 关联equ 到当前对象的 槽函数 */
		connect(equ,SIGNAL(clicked()),
						this,SLOT(getCompRes()));
}
Adder::~Adder(){
    delete add;
		delete oper;
		delete added;
		delete equ;
		delete res;
}
/* 完成计算的自定义槽函数 */
void   Adder::getCompRes(){
    //res->setText("9527");
		/* 点击按钮之后 把add中输入的值赋值给res*/
    /* 获取 add  added中输入的值 */
		/*QString sadd=add->text();
		QString sadded=added->text();
    // 转换成整数 
    int    iadd=sadd.toInt();
		int    iadded=sadded.toInt();
    int    isum=iadd+iadded;
		//  把相加之后的整数和变成字符串 
		res->setText(QString::number(isum));*/
    res->setText(QString::number(
				add->text().toInt()+
				added->text().toInt()));
}


