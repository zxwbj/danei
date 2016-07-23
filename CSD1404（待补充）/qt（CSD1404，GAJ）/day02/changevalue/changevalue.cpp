#include <QApplication>
#include <QDialog>
#include <QSlider>
#include <QSpinBox>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    QDialog   *parentw;
		QSlider   *qsli;
		QSpinBox  *qspin;
		parentw=new QDialog();
		parentw->resize(400,500);
    qsli=new QSlider(parentw);
		qsli->resize(20,200);
		qspin=new QSpinBox(parentw);
    /* 调整组建位置 */
		qsli->move(50,150);
		qspin->move(200,250);
    parentw->show();
		/* 连接带参的信号和 槽 */
    QObject::connect(qsli,
				SIGNAL(valueChanged(int)),
				qspin,SLOT(setValue(int)));
    QObject::connect(qspin,
				SIGNAL(valueChanged(int)),
				qsli,SLOT(setValue(int)));
    /* 槽函数可以像普通成员函数去调用 */
		qspin->setValue(60);
		return  app.exec();
}

