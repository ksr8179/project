#include "client.h"
#include "ui_publicwindow.h"
#include <QHostAddress>
#include <string>
#include "publicwindow.h"
#include "ui_publicwindow.h"

Client::Client(QObject* parent): QObject(parent)
{
  connect(client, SIGNAL(connected()),
    this, SLOT(connected()));
  connect(publicWindow::on_bookListBtn_clicked(), SIGNAL(clicked()),
    this, SLOT(startTransfer()));
}

Client::~Client()
{
  client->close();
}
void Client::connected(){

}
void Client::start(QString address, quint16 port)
{
  QHostAddress addr(address);
  client->connectToHost(addr, port);
}

void Client::getText(QString s){
    this->s=s;
}

void Client::startTransfer()
{
  client->write(s.toUtf8().constData());
}
