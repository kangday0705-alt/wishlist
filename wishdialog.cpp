#include "wishdialog.h"
#include "ui_wishdialog.h"
#include "Wish.h"
#include <QInputDialog>
#include <QMessageBox>

WishDialog::WishDialog(QWidget *parent, const Wish *nwish)
    : QDialog(parent)
    , ui(new Ui::WishDialog)
{
    ui->setupUi(this);
    if(nwish){
        ui->nameEdit->setText(QString::fromStdString(nwish->name));
        ui->balanceEdit->setText(QString::number(nwish->getBalance()));
        ui->dateEdit->setDate(QDate(nwish->getDate().year, nwish->getDate().month, nwish->getDate().day));

        for(const Checklist &c : nwish->getChecklistConst()){
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(c.check));
            item->setFlags(item->flags()|Qt::ItemIsUserCheckable);
            item->setCheckState(c.getisCheckAchieved()? Qt::Checked : Qt::Unchecked);
            ui->checklist->addItem(item);
        }
    }
    else{
        ui->btndelete->hide();
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
    QString name = QInputDialog::getText(this, "체크리스트 추가", "추가할 체크리스트", QLineEdit::Normal, "", &ok);
    if(ok&&!name.isEmpty()){
        QListWidgetItem *item = new QListWidgetItem(name);
        item->setFlags(item->flags()|Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        ui->checklist->addItem(item);
    }
}

//위시삭제
void WishDialog::on_pushButton_clicked()
{
    if(QMessageBox::question(this,"경고","위시를 삭제할까요?")==QMessageBox::Yes){
        done(2);
    }

}

//체크리스트 삭제
void WishDialog::on_btndelete_clicked()
{
    delete ui->checklist->currentItem();
}

QString WishDialog::getName()
{
    return ui->nameEdit->text();
}

int WishDialog::getBalance()
{
    return ui->balanceEdit->text().toInt();
}

Date WishDialog::getDate()
{
    QDate d = ui->dateEdit->date();
    return Date(d.year(),d.month(),d.day());
}

vector<Checklist> WishDialog::getChecklist()
{
    vector<Checklist> rt;
    for(int i = 0; i<ui->checklist->count();i++){
        Checklist c;
        c.setisCheckAchieved(ui->checklist->item(i)->checkState()==Qt::Checked);
        c.check=ui->checklist->item(i)->text().toStdString();
        rt.push_back(c);
    }
    return rt;
}