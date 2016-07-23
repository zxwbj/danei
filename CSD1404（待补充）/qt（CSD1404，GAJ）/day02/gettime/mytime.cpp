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
}
MyTime::~MyTime(){
    delete  showtime;
		delete  gettime;
}
		/* 完成获取时间的自定义槽函数 */
void   MyTime::getCurrTime(){
    QString  mytime=
		QTime::currentTime().toString("hh:mm:ss");
		showtime->setText(mytime);

}


