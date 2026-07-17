#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Wishlist.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_btnadd_clicked();

private:
    Ui::MainWindow *ui;

    Wishlist wishlist;
};
#endif // MAINWINDOW_H
