#ifndef  ADDER_H
#define  ADDER_H
#include <QDialog>
#include "jfq.h"
class  Adder:public QDialog{
		Q_OBJECT
    private:
	  /* 定义一个界面指针 */			
    Ui_Dialog  *ui;
		public:
		Adder();
		~Adder();
		public slots:
	  void  getCompRes();			
};  
#endif


