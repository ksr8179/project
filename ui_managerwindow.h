/********************************************************************************
** Form generated from reading UI file 'managerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERWINDOW_H
#define UI_MANAGERWINDOW_H

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

class Ui_ManagerWindow
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
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QFrame *frame_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *ManagerWindow)
    {
        if (ManagerWindow->objectName().isEmpty())
            ManagerWindow->setObjectName(QStringLiteral("ManagerWindow"));
        ManagerWindow->resize(503, 354);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ManagerWindow->sizePolicy().hasHeightForWidth());
        ManagerWindow->setSizePolicy(sizePolicy);
        ManagerWindow->setMinimumSize(QSize(503, 354));
        ManagerWindow->setMaximumSize(QSize(503, 354));
        centralwidget = new QWidget(ManagerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 130, 481, 211));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 171, 111));
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
        pushButton->setGeometry(QRect(120, 80, 41, 21));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 80, 52, 16));
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 80, 51, 16));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 50, 91, 61));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 20, 91, 21));
        label_4->setFont(font);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(190, 10, 171, 111));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 10, 61, 21));
        label_6->setFont(font);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 40, 52, 15));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 60, 51, 16));
        lineEdit_4 = new QLineEdit(frame_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(60, 40, 101, 16));
        lineEdit_5 = new QLineEdit(frame_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(60, 60, 101, 16));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 80, 41, 21));
        ManagerWindow->setCentralWidget(centralwidget);

        retranslateUi(ManagerWindow);

        QMetaObject::connectSlotsByName(ManagerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerWindow)
    {
        ManagerWindow->setWindowTitle(QApplication::translate("ManagerWindow", "\352\264\200\353\246\254\354\236\220 \353\252\250\353\223\234", 0));
        label->setText(QApplication::translate("ManagerWindow", "\353\217\204\354\204\234 \354\266\224\352\260\200", 0));
        label_2->setText(QApplication::translate("ManagerWindow", "\354\261\205 \354\235\264 \353\246\204 : ", 0));
        label_3->setText(QApplication::translate("ManagerWindow", "\354\266\234 \355\214\220 \354\202\254 : ", 0));
        pushButton->setText(QApplication::translate("ManagerWindow", "\355\231\225   \354\235\270", 0));
        label_5->setText(QApplication::translate("ManagerWindow", "\354\210\230     \353\237\211 :", 0));
        pushButton_2->setText(QApplication::translate("ManagerWindow", "\355\201\264    \353\246\255", 0));
        label_4->setText(QApplication::translate("ManagerWindow", "\353\217\204\354\204\234 \353\252\251\353\241\235 \353\263\264\352\270\260", 0));
        label_6->setText(QApplication::translate("ManagerWindow", "\353\217\204\354\204\234 \354\202\255\354\240\234", 0));
        label_7->setText(QApplication::translate("ManagerWindow", "\354\261\205 \354\235\264 \353\246\204 : ", 0));
        label_8->setText(QApplication::translate("ManagerWindow", "\354\266\234 \355\214\220 \354\202\254 : ", 0));
        pushButton_3->setText(QApplication::translate("ManagerWindow", "\355\231\225   \354\235\270", 0));
    } // retranslateUi

};

namespace Ui {
    class ManagerWindow: public Ui_ManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERWINDOW_H
