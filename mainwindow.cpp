#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wishdialog.h"
#include <QMessageBox>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow(){
    delete ui;
}

//위시 추가
void MainWindow::on_btnadd_clicked()
{
    WishDialog dialog(this);
    dialog.exec();
}



void MainWindow::on_btnbuy_clicked()
{
    int idx;
        //인덱스 확인

}

//위시 수정
void MainWindow::on_listwish_itemClicked(QListWidgetItem *item)
{
    WishDialog dialog(this);
    dialog.exec();
}


void MainWindow::on_btnsave_clicked()
{
    bool ok;
    int save = QInputDialog::getInt(this, "저축", "저축할 금액", 0, 0,100000000, 1000, &ok);
    wishlist.addcurrBalance(save);
    //잔액표시, 리스트 표시
}

