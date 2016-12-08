﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "publicwindow.h"
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client = new QTcpSocket(this);
    connect(client, SIGNAL(connected()),
      this, SLOT(connected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connected(){

}

void MainWindow::start(QString address, quint16 port){
    QHostAddress addr(address);
    client->connectToHost(addr, port);
}


void MainWindow::on_managerPushBtn_clicked()
{
    loginWindow* loginwindow = new loginWindow(this, "loginWindow");
    loginwindow->show();
    qDebug("loginwindow->show()");
}

void MainWindow::on_publicPushBtn_clicked()
{
    publicWindow * publicwindow = new publicWindow(this,"publicWindow");
    publicwindow->show();
    qDebug("publicwindow->show()");
}
