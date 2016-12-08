#ifndef MYHEADER_H
#define MYHEADER_H
#include <qwidget.h>

class mywid:public QWidget
{
Q_OBJECT
public:
mywid();
private slots:
void slotTimer();
private:
void paintEvent(QPaintEvent*);
QTimer* timer;
};

#endif // MYHEADER_H
