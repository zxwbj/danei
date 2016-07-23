#include <QApplication>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    QDialog  *parentw;
		QLineEdit *uname;
		QLineEdit *upasswd;
		QPushButton *blogin;
		QPushButton *bcancel;
    /* 创建父窗口 */
		parentw=new QDialog();
		parentw->resize(400,300);
    /* 给界面指针赋值 */
		uname=new QLineEdit(parentw);
    upasswd=new QLineEdit(parentw);
    blogin=new QPushButton("login",parentw);
		bcancel=new QPushButton("cancel",parentw);
    /* 调整组建的位置 */
		uname->move(200,50);
		upasswd->move(200,100);
    blogin->move(50,200);
		bcancel->move(250,200);
		parentw->show();
		/* 点击cancel按钮 关闭父窗口 */
		QObject::connect(bcancel,
				SIGNAL(clicked()),
				parentw,SLOT(close()));
		return  app.exec();
}



