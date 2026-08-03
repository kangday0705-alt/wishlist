#ifndef HISTORYDIALOG_H
#define HISTORYDIALOG_H

#include <QDialog>
#include "Wishlist.h"
#include <QListWidgetItem>

namespace Ui {
class HistoryDialog;
}

class HistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryDialog(Wishlist &wishlist, QWidget *parent = nullptr);
    ~HistoryDialog();

private slots:
    void on_wishhistory_itemClicked(QListWidgetItem *item);

private:
    Ui::HistoryDialog *ui;

    void refreshlist();
    Wishlist &w;
};

#endif // HISTORYDIALOG_H
