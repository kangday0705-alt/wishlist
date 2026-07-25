#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wishdialog.h"
#include <QMessageBox>
#include <QInputDialog>


//생성자
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    wishlist.loadFromFile();
    refreshBalance();
    refreshList();
}

//소멸자
MainWindow::~MainWindow(){

    wishlist.saveToFile();
    delete ui;
}

//위시 추가
void MainWindow::on_btnadd_clicked()
{
    WishDialog dialog(this);
    if(dialog.exec()==1){

        Wish w;
        w.name=dialog.getName().toStdString();
        w.setBalance(dialog.getBalance(), wishlist.getcurrBalance());
        w.setDate(dialog.getDate(), wishlist.getcurrBalance());
        w.setChecklist(dialog.getChecklist(), wishlist.getcurrBalance());

        wishlist.addwish(w);

        refreshList();
    }
}


//위시구매(완료후삭제)
void MainWindow::on_btnbuy_clicked()
{
    int idx = ui->listwish->currentRow();

    if(idx==-1){
        QMessageBox::warning(this,"알림","완료할 위시를 선택하세요");
    }
    else{
        if(QMessageBox::question(this,"알림",QString::fromStdString(wishlist.getwish(idx).name)+"완료한 위시는 삭제됩니다")==QMessageBox::Yes)
        {
            wishlist.deletewish(idx);
            refreshList();
        }
    }
}

//위시 수정
void MainWindow::on_listwish_itemClicked()
{
    Wish &w = wishlist.getwish(ui->listwish->currentRow());

    WishDialog dialog(this, &w);
    int re = dialog.exec();

    if(re==1){

    w.name=dialog.getName().toStdString();
    w.setBalance(dialog.getBalance(), wishlist.getcurrBalance());
    w.setDate(dialog.getDate(), wishlist.getcurrBalance());
    w.setChecklist(dialog.getChecklist(), wishlist.getcurrBalance());

    refreshList();
    }

    if(re==2){
        wishlist.deletewish(ui->listwish->currentRow());
        refreshList();
    }

}

//저축
void MainWindow::on_btnsave_clicked()
{
    bool ok;
    int save = QInputDialog::getInt(this, "저축", "저축할 금액", 0, 0,100000000, 1000, &ok);

    if(ok){
    wishlist.addcurrBalance(save);
    refreshBalance();
    refreshList();
    }
}


void MainWindow::refreshList(){
    ui->listwish->clear();

    for(int i=0; i<wishlist.size(); i++){
        ui->listwish->addItem(QString::fromStdString(wishlist.getwish(i).name));
    }
}

void MainWindow::refreshBalance(){
    ui->labelbalance->setText("현재 잔고: " + QString::number(wishlist.getcurrBalance()) +"원");
}
