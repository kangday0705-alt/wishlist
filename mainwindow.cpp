#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wishdialog.h"
#include "historydialog.h"
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


//위시구매
void MainWindow::on_btnbuy_clicked()
{

    QListWidgetItem *item =ui->listwish->currentItem();

    if(item==nullptr){
        QMessageBox::warning(this,"알림","Select a wish to complete.");
    }

    else{
        int idx = item->data(Qt::UserRole).toInt();
        if(QMessageBox::question(this,"알림",QString::fromStdString(wishlist.getwish(idx).name)+": Completed wishes are moved to History.")==QMessageBox::Yes)
        {
            if(!wishlist.getwish(idx).getIsUnlocked()){
                QMessageBox::warning(this,"알림",QString::fromStdString(wishlist.getwish(idx).name)+" is locked.");
            }
            wishlist.getwish(idx).buyWish();

            //wishlist.deletewish(idx);
            refreshList();
        }
    }
}

//위시 수정
void MainWindow::on_listwish_itemDoubleClicked()
{
    Wish &w = wishlist.getwish(ui->listwish->currentItem()->data(Qt::UserRole).toInt());

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
        wishlist.deletewish(ui->listwish->currentItem()->data(Qt::UserRole).toInt());
        refreshList();
    }

}

//저축
void MainWindow::on_btnsave_clicked()
{
    bool ok;
    int save = QInputDialog::getInt(this, "Save", "Amount to Save", 0, -100000000, 100000000, 1000, &ok);

    if(ok){
        if(save<-wishlist.getcurrBalance()){
            QMessageBox::warning(this,"알림", "Cannot withdraw more than the current balance.");
        }
        else{
        wishlist.addcurrBalance(save);
        refreshBalance();
        refreshList();
        }
    }
}

void MainWindow::refreshList(){
    ui->listwish->clear();

    for(int i=0; i<wishlist.size(); i++){
        Wish &w = wishlist.getwish(i);

        if(w.getIsUnlocked()&&!w.getIsCompleted()){
            QListWidgetItem *item = new QListWidgetItem(QString("⭐ ")+QString::fromStdString(w.name));
            item->setData(Qt::UserRole, i);
            ui->listwish->addItem(item);
        }
    }

    for(int i=0; i<wishlist.size(); i++){
        Wish &w = wishlist.getwish(i);

        if(!w.getIsUnlocked()){
            QListWidgetItem *item = new QListWidgetItem(QString("🔒 ")+QString::fromStdString(w.name));
            item->setData(Qt::UserRole, i);
            ui->listwish->addItem(item);
        }
    }

}

void MainWindow::refreshBalance(){
    ui->labelbalance->setText(QString::number(wishlist.getcurrBalance()) +" ₩");
}

//히스토리 열람
void MainWindow::on_pushButton_clicked()
{
    HistoryDialog dialog(wishlist, this);
    dialog.exec();

}

