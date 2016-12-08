#ifndef MANAGERWINDOW_H
#define MANAGERWINDOW_H

#include <QMainWindow>

namespace Ui {
class ManagerWindow;
}

class ManagerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerWindow(QWidget *parent = 0, const char *name=0, bool modal=false, Qt::WindowFlags f = 0);
    ~ManagerWindow();

private:
    Ui::ManagerWindow *ui;
};

#endif // MANAGERWINDOW_H
