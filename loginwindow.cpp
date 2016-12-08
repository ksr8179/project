#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "managerwindow.h"
#include <QDesktopWidget>
#include <iostream>
loginWindow::loginWindow(QWidget *parent, const char *name, bool modal, Qt::WindowFlags f) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //스크린 중앙에 창 띄우는 코드
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_pushButton_clicked()
{

    ui->idEdit->text().toUtf8().constData();
    ui->pwdEdit->text().toUtf8().constData();

    std::cout<<ui->idEdit->text().toUtf8().constData();
    std::cout<<"\n";
    std::cout<<ui->pwdEdit->text().toUtf8().constData();
    std::cout<<"\n";
    ManagerWindow * managerwindow = new ManagerWindow(this,"managerwindow");
    managerwindow->show();
    qDebug("managerwindow->show()");

}
