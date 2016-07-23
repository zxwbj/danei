#include "mytime.h"		
#include <QTime>
MyTime::MyTime(){
		this->resize(400,500);
    showtime=new QLabel("current time",this);
		gettime=new QPushButton("gettime",this);
    showtime->move(150,50);
		gettime->move(150,400);
		connect(gettime,SIGNAL(clicked()),this,
						SLOT(getCurrTime()));
		/* 连接自定义信号 到目标槽函数 */
		connect(this,SIGNAL(mySig(QString)),
						showtime,SLOT(setText(QString)));
}
MyTime::~MyTime(){
    delete  showtime;
		delete  gettime;
}
		/* 完成获取时间的自定义槽函数 */
void   MyTime::getCurrTime(){
    QString  mytime=
		QTime::currentTime().toString("hh:mm:ss");
		// showtime->setText(mytime);
		/* 发射自定义信号 */
    emit mySig(mytime);
}


