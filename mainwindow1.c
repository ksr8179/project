#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H
 
#include <QMainWindow>
#include "secdialog1.h"
namespace Ui {
class MainWindow;
}
 
class MainWindow : public QMainWindow
{
    Q_OBJECT
 
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
 
private slots:
    void on_pushButton_Login_clicked();
 
private:
    Ui::MainWindow *ui;
    SecDialog *secDialog;
};
 
#endif // MAINWINDOW_H

