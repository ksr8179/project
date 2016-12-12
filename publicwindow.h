#ifndef PUBLICWINDOW_H
#define PUBLICWINDOW_H

#include <QtNetwork>
#include <QObject>
#include <QMainWindow>
#include <QTcpSocket>
#include <string>


namespace Ui {
class publicWindow;
}

class publicWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit publicWindow(QWidget *parent = 0, const char *name=0, bool modal=false, Qt::WindowFlags f = 0);
    ~publicWindow();

    void start(QString address, quint16 port);
private slots:
    void on_bookListBtn_clicked();
    void connected();
    void startTransfer();

private:
    Ui::publicWindow *ui;

    enum column{
        bno,bname,pub,num
    };
    QTcpSocket *client;
};

#endif // PUBLICWINDOW_H
