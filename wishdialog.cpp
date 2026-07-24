#include "wishdialog.h"
#include "ui_wishdialog.h"
#include <QInputDialog>
#include <QMessageBox>

WishDialog::WishDialog(QWidget *parent, const Wish *wish)
    : QDialog(parent)
    , ui(new Ui::WishDialog)
{
    ui->setupUi(this);
    if(wish){

    }
    else{

    }
}

WishDialog::~WishDialog()
{
    delete ui;
}

//체크리스트 추가
void WishDialog::on_btnadd_clicked()
{
    bool ok;
    QInputDialog::getText(this, "체크리스트 추가", "추가할 체크리스트", QLineEdit::Normal, "", &ok);
}

//위시삭제
void WishDialog::on_pushButton_clicked()
{

}

//체크리스트 삭제
void WishDialog::on_btndelete_clicked()
{

}

