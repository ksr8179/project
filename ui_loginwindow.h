/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName(QStringLiteral("loginWindow"));
        loginWindow->resize(299, 130);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginWindow->sizePolicy().hasHeightForWidth());
        loginWindow->setSizePolicy(sizePolicy);
        loginWindow->setMinimumSize(QSize(299, 130));
        loginWindow->setMaximumSize(QSize(299, 130));
        centralwidget = new QWidget(loginWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 70, 113, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 91, 31));
        QFont font;
        font.setPointSize(21);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 100, 113, 23));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 52, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 52, 15));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 70, 91, 51));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        loginWindow->setCentralWidget(centralwidget);

        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *loginWindow)
    {
        loginWindow->setWindowTitle(QApplication::translate("loginWindow", "\352\264\200\353\246\254\354\236\220 \353\241\234\352\267\270\354\235\270", 0));
        label_3->setText(QApplication::translate("loginWindow", "\352\264\200\353\246\254\354\236\220", 0));
        label->setText(QApplication::translate("loginWindow", "\354\225\204\354\235\264\353\224\224 : ", 0));
        label_2->setText(QApplication::translate("loginWindow", "\353\271\204\353\260\200\353\262\210\355\230\270 : ", 0));
        pushButton->setText(QApplication::translate("loginWindow", "\353\241\234\352\267\270\354\235\270", 0));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
