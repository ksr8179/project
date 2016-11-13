/********************************************************************************
** Form generated from reading UI file 'publicwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBLICWINDOW_H
#define UI_PUBLICWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_publicWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *publicWindow)
    {
        if (publicWindow->objectName().isEmpty())
            publicWindow->setObjectName(QStringLiteral("publicWindow"));
        publicWindow->resize(370, 349);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(publicWindow->sizePolicy().hasHeightForWidth());
        publicWindow->setSizePolicy(sizePolicy);
        publicWindow->setMinimumSize(QSize(370, 349));
        publicWindow->setMaximumSize(QSize(370, 349));
        centralwidget = new QWidget(publicWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 110, 351, 231));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 241, 91));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 61, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 52, 15));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 51, 16));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 40, 101, 16));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 60, 101, 16));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 40, 61, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 10, 91, 21));
        label_4->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 40, 91, 61));
        publicWindow->setCentralWidget(centralwidget);

        retranslateUi(publicWindow);

        QMetaObject::connectSlotsByName(publicWindow);
    } // setupUi

    void retranslateUi(QMainWindow *publicWindow)
    {
        publicWindow->setWindowTitle(QApplication::translate("publicWindow", "\354\235\274\353\260\230 \353\252\250\353\223\234", 0));
        label->setText(QApplication::translate("publicWindow", "\353\217\204\354\204\234 \352\262\200\354\203\211", 0));
        label_2->setText(QApplication::translate("publicWindow", "\354\261\205 \354\235\264 \353\246\204 : ", 0));
        label_3->setText(QApplication::translate("publicWindow", "\354\266\234 \355\214\220 \354\202\254 : ", 0));
        pushButton->setText(QApplication::translate("publicWindow", "\352\262\200   \354\203\211", 0));
        label_4->setText(QApplication::translate("publicWindow", "\353\217\204\354\204\234 \353\252\251\353\241\235 \353\263\264\352\270\260", 0));
        pushButton_2->setText(QApplication::translate("publicWindow", "\355\201\264    \353\246\255", 0));
    } // retranslateUi

};

namespace Ui {
    class publicWindow: public Ui_publicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLICWINDOW_H
