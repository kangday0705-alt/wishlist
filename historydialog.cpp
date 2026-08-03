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
            ui->wishhistory->addItem(QString::fromStdString(w.getwish(i).name));
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
    dialog.exec();

}

