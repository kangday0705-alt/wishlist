#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnadd_clicked()
{
    //위시 추가. wishdialog창 표시
}



void MainWindow::on_btnbuy_clicked()
{
    //인덱스 확인
    //위시 컴플릿
}

