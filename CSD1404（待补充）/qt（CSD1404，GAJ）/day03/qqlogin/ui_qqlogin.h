/********************************************************************************
** Form generated from reading UI file 'qqlogin.ui'
**
** Created: Mon Jul 21 09:19:18 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QQLOGIN_H
#define UI_QQLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QqLogin
{
public:
    QPushButton *blogin;
    QPushButton *bcancel;
    QLineEdit *uname;
    QLineEdit *upasswd;

    void setupUi(QDialog *QqLogin)
    {
        if (QqLogin->objectName().isEmpty())
            QqLogin->setObjectName(QString::fromUtf8("QqLogin"));
        QqLogin->resize(322, 233);
        blogin = new QPushButton(QqLogin);
        blogin->setObjectName(QString::fromUtf8("blogin"));
        blogin->setGeometry(QRect(60, 170, 85, 27));
        bcancel = new QPushButton(QqLogin);
        bcancel->setObjectName(QString::fromUtf8("bcancel"));
        bcancel->setGeometry(QRect(193, 168, 85, 27));
        uname = new QLineEdit(QqLogin);
        uname->setObjectName(QString::fromUtf8("uname"));
        uname->setGeometry(QRect(150, 30, 113, 25));
        QFont font;
        font.setPointSize(20);
        uname->setFont(font);
        upasswd = new QLineEdit(QqLogin);
        upasswd->setObjectName(QString::fromUtf8("upasswd"));
        upasswd->setGeometry(QRect(150, 90, 113, 25));
        upasswd->setFont(font);
        upasswd->setEchoMode(QLineEdit::Password);

        retranslateUi(QqLogin);

        QMetaObject::connectSlotsByName(QqLogin);
    } // setupUi

    void retranslateUi(QDialog *QqLogin)
    {
        QqLogin->setWindowTitle(QApplication::translate("QqLogin", "QqLogin", 0, QApplication::UnicodeUTF8));
        blogin->setText(QApplication::translate("QqLogin", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        bcancel->setText(QApplication::translate("QqLogin", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QqLogin: public Ui_QqLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QQLOGIN_H
