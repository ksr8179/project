#include "managerwindow.h"
#include "ui_managerwindow.h"
#include <QDesktopWidget>

ManagerWindow::ManagerWindow(QWidget *parent, const char *name, bool modal, Qt::WindowFlags f) :
    QMainWindow(parent),
    ui(new Ui::ManagerWindow)
{
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //스크린 중앙에 창 띄우는 코드
    ui->setupUi(this);
}

ManagerWindow::~ManagerWindow()
{
    delete ui;
}
