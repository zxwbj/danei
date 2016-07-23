#include <QApplication>
#include <QTextCodec>
#include <QtGui/QLabel>
int main(int argc,char** argv){
    /* 构建一个应用程序对象 */
		QApplication  app(argc,argv);
		/* 构建一个编码对象 */
		QTextCodec  *coder=
				QTextCodec::codecForName("UTF-8");
    /* 构建一个标签对象 */
		QLabel   qlab(
				coder->toUnicode("你好 qt!"));
		qlab.show();
		/* 让程序进入事件循环 */
		return  app.exec();
}

