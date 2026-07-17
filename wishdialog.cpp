#include "wishdialog.h"
#include "ui_wishdialog.h"

WishDialog::WishDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WishDialog)
{
    ui->setupUi(this);
}

WishDialog::~WishDialog()
{
    delete ui;
}
