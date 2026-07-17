#ifndef WISHDIALOG_H
#define WISHDIALOG_H

#include <QDialog>

namespace Ui {
class WishDialog;
}

class WishDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WishDialog(QWidget *parent = nullptr);
    ~WishDialog();

private:
    Ui::WishDialog *ui;
};

#endif // WISHDIALOG_H
