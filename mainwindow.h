#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void start(QString address, quint16 port);
private slots:
    void connected();
    void on_managerPushBtn_clicked();
    void on_publicPushBtn_clicked();
    void startTransfer();
    void readAll();

private:
    Ui::MainWindow *ui;
    QTcpSocket *client;
};

#endif // MAINWINDOW_H
