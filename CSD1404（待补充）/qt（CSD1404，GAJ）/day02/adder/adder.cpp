#include <QApplication>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    QDialog    *parent;
		QLineEdit  *add;
		QLabel     *oper;
                QLineEdit  *added;
		QPushButton *equ;
		QLineEdit   *res;
    /* 指针赋值 */
		parent=new QDialog();
		parent->resize(650,300);
		/* 给界面中组件指针赋值 */
    add=new QLineEdit(parent);
    oper=new QLabel("+",parent);
    added=new QLineEdit(parent);
    equ=new QPushButton("=",parent);
    res=new QLineEdit(parent);
		/* 调整位置 */
    add->move(20,130);
    oper->move(170,130);
    added->move(220,130);
    equ->move(360,130);
    res->move(470,130);
		parent->show();
		return  app.exec();
}

