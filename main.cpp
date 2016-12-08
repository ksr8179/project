#include "mainwindow.h"
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include "client.h"
#include <QApplication>
#include "publicwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.start("127.0.0.1", 9190);

    QRect screenGeometry = QApplication::desktop()->screenGeometry(); //스크린의 geometry를 구함.

    int x = (screenGeometry.width()-w.width()) / 2; //화면의 x축 값을 구함

    int y = (screenGeometry.height()-w.height()) / 2; //화면의 y축 값을 구함

    w.move(x, y); //MainWindow창을 이동시킴
    w.show();

    return a.exec();
}
