#ifndef QQLOGIN_H
#define QQLOGIN_H

#include <QDialog>

namespace Ui {
class QqLogin;
}

class QqLogin : public QDialog
{
    Q_OBJECT
    
public:
    explicit QqLogin(QWidget *parent = 0);
    ~QqLogin();
    
private:
    Ui::QqLogin *ui;
/* 完成 取消 和 登录 */
public  slots:
    void   loginAndCancel();
};

#endif // QQLOGIN_H



