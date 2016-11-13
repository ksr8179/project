/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *managerPushBtn;
    QPushButton *publicPushBtn;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(350, 199);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(350, 199));
        MainWindow->setMaximumSize(QSize(350, 199));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        managerPushBtn = new QPushButton(centralWidget);
        managerPushBtn->setObjectName(QStringLiteral("managerPushBtn"));
        managerPushBtn->setGeometry(QRect(250, 150, 91, 41));
        publicPushBtn = new QPushButton(centralWidget);
        publicPushBtn->setObjectName(QStringLiteral("publicPushBtn"));
        publicPushBtn->setGeometry(QRect(250, 100, 91, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 201, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\353\214\200\355\225\231 \354\240\225\353\263\264 \354\213\234\354\212\244\355\205\234", 0));
        managerPushBtn->setText(QApplication::translate("MainWindow", "\352\264\200  \353\246\254  \354\236\220", 0));
        publicPushBtn->setText(QApplication::translate("MainWindow", "\354\235\274   \353\260\230", 0));
        label->setText(QApplication::translate("MainWindow", "\353\217\204\354\204\234 \352\264\200\353\246\254 \354\213\234\354\212\244\355\205\234", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
