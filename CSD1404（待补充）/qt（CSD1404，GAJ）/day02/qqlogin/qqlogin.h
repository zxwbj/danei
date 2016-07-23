#ifndef  QQLOGIN_H
#define  QQLOGIN_H
#include "qq.h"
#include <QDialog>
class  QqLogin:public QDialog{
		Q_OBJECT
		/* 定义界面指针 */
    private:
	  Ui_Dialog *ui;
		public:
		QqLogin();
		~QqLogin();
		/* 负责登入 和 退出的槽函数 */
		public slots:
    void   loginAndCancel();
}; 
#endif
