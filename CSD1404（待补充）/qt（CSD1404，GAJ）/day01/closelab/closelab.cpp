#include <QApplication>
#include <QLabel>
#include <QPushButton>
int main(int argc,char** argv){
		QApplication  app(argc,argv);
    QLabel   qlab("hello qt!");
		qlab.show();
		QPushButton *qpush
				=new QPushButton("closelab");
		qpush->show();
		/* 点击按钮 就 关闭标签 
    QObject::connect(qpush,SIGNAL(clicked()),
				&qlab,SLOT(close())); */
    /* 点击按钮  关闭应用程序 */
    QObject::connect(qpush,SIGNAL(clicked()),
				&app,SLOT(quit())); 
		return  app.exec();
}

