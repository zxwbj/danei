#ifndef  ADDER_H
#define  ADDER_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
class  Adder:public QDialog{
		 Q_OBJECT
     QLineEdit  *add;
     QLabel     *oper;
     QLineEdit  *added;
     QPushButton *equ;
     QLineEdit   *res;
     public:
		 Adder();
     ~Adder();
     /* 完成计算的自定义槽函数 */
		 public slots:
     void   getCompRes();
}; 
#endif
