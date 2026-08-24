#include "historydialog.h"
#include "ui_historydialog.h"
#include "wishdialog.h"

HistoryDialog::HistoryDialog(Wishlist &wishlist, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HistoryDialog)
    ,w(wishlist)
{
    ui->setupUi(this);
    refreshlist();
}

void HistoryDialog::refreshlist()
{
    ui->wishhistory->clear();

    for(int i = 0; i<w.size();i++){
        if(w.getwish(i).getIsCompleted()){
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(w.getwish(i).name));
            item->setData(Qt::UserRole, i);
            ui->wishhistory->addItem(item);
        }
    }
}

HistoryDialog::~HistoryDialog()
{
    delete ui;
}

void HistoryDialog::on_wishhistory_itemClicked(QListWidgetItem *item)
{
    Wish &W = w.getwish(ui->wishhistory->currentItem()->data(Qt::UserRole).toInt());

    WishDialog dialog(this, &W);
    int re = dialog.exec();
    if(re==2){
        w.deletewish(ui->wishhistory->currentItem()->data(Qt::UserRole).toInt());
        refreshlist();
    }

}

