#ifndef CLIENT_H
#define CLIENT_H


#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include<string>

class Client: public QObject
{
Q_OBJECT
public:

  Client(QObject* parent = 0);
  ~Client();
  void start(QString address, quint16 port);
  void getText(QString s);
public slots:
  void connected();
  void request();
  void startTransfer();
private:
  QString s;
  QTcpSocket *client;

};

#endif // CLIENT_H
