#ifndef  MYTIME_H
#define  MYTIME_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
class  MyTime:public QDialog{
		Q_OBJECT
    private:
		QLabel   *showtime;
		QPushButton *gettime;
		public:
		MyTime();
		~MyTime();
		/* 完成获取时间的自定义槽函数 */
		public  slots:
		void   getCurrTime();
    /* 自定义信号 函数 */
		public:signals:
		void   mySig(QString msg);			 
};
#endif



