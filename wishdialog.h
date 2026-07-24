#ifndef WISHDIALOG_H
#define WISHDIALOG_H

#include <QDialog>
#include "Wish.h"

namespace Ui {
class WishDialog;
}

class WishDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WishDialog(QWidget *parent = nullptr, const Wish *wish =nullptr);
    ~WishDialog();

private slots:
    void on_btnadd_clicked();
    void on_pushButton_clicked();
    void on_btndelete_clicked();

private:
    Ui::WishDialog *ui;
};

#endif // WISHDIALOG_H
