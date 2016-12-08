#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class loginWindow;
}

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0, const char *name=0, bool modal=false, Qt::WindowFlags f = 0);

    ~loginWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::loginWindow *ui;
};

#endif // LOGINWINDOW_H
