/********************************************************************************
** Form generated from reading UI file 'qq.ui'
**
** Created: Sat Jul 19 16:52:20 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QQ_H
#define QQ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *blogin;
    QPushButton *bcancel;
    QLineEdit *uname;
    QLineEdit *upasswd;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(312, 223);
        blogin = new QPushButton(Dialog);
        blogin->setObjectName(QString::fromUtf8("blogin"));
        blogin->setGeometry(QRect(40, 160, 85, 27));
        bcancel = new QPushButton(Dialog);
        bcancel->setObjectName(QString::fromUtf8("bcancel"));
        bcancel->setGeometry(QRect(180, 160, 85, 27));
        uname = new QLineEdit(Dialog);
        uname->setObjectName(QString::fromUtf8("uname"));
        uname->setGeometry(QRect(140, 30, 113, 25));
        upasswd = new QLineEdit(Dialog);
        upasswd->setObjectName(QString::fromUtf8("upasswd"));
        upasswd->setGeometry(QRect(140, 80, 113, 25));
        upasswd->setEchoMode(QLineEdit::Password);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        blogin->setText(QApplication::translate("Dialog", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        bcancel->setText(QApplication::translate("Dialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QQ_H
