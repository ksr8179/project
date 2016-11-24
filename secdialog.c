#include "secdialog1.h"
#include "ui_secdialog1.h"
 
SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}
 
SecDialog::~SecDialog()
{
    delete ui;
}

