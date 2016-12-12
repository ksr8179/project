#include "publicwindow.h"
#include "ui_publicwindow.h"
#include <QDesktopWidget>
#include"client.h"
#include<QHostAddress>
#include <QString>
#include <QHostAddress>

#define BUFF_SIZE 30

publicWindow::publicWindow(QWidget *parent, const char *name, bool modal, Qt::WindowFlags f) :
    QMainWindow(parent),
    ui(new Ui::publicWindow)
{
    this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center()); //스크린 중앙에 창 띄우는 코드

    ui->setupUi(this);
    QStringList title;
    client = new QTcpSocket(this);
    connect(client, SIGNAL(connected()),
      this, SLOT(startTransfer()));
    connect(client,SIGNAL(connected()),SLOT(readAll()));
   // connect(client,SIGNAL(connected()),this,SLOT(startTransfer()));
    ui->tableWidget->setColumnCount(4);
    title<<"책번호"<<"책이름"<<"출판사"<<"수량";
    ui->tableWidget->setHorizontalHeaderLabels(title);

}

void publicWindow::connected(){
    //start("127.0.0.1",9190);
}

void publicWindow::startTransfer(){
    client->write("1");
}


publicWindow::~publicWindow()
{
    client->close();
    delete ui;
}


void publicWindow::on_bookListBtn_clicked()
{

    QString s = ui->lineEdit->text().toUtf8().trimmed();
    //client->write(s.toUtf8());
    qDebug() <<s;
    ui->tableWidget->removeRow(ui->tableWidget->rowCount());
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    for(int i=0;i<=10;i++){
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,bname,
                             new QTableWidgetItem("name"));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->lineEdit->clear();
    }

}
