#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    /* 创建一个父窗口对象 */
		QWidget  *parentw=new QWidget();
		parentw->resize(400,600);
		/* 创建一个按钮对象 */
		QPushButton *qpush=
				new QPushButton("close lab",parentw);
		qpush->move(150,500);
    // qpush->show();
    QLabel   *qlab=
				new QLabel("hello qt!",parentw);
		qlab->move(150,50);
		// qlab->show();
		parentw->show();
		/* 点击按钮 关闭标签 
		QObject::connect(qpush,SIGNAL(clicked()),
				qlab,SLOT(close())); */
		/* 点击按钮 关闭父窗口 */
		QObject::connect(qpush,SIGNAL(clicked()),
				parentw,SLOT(close()));
		return  app.exec();
}

