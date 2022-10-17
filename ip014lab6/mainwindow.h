#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bessonov_miheev.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bessonov_miheev *myform;

signals:
    void sendData(QString str);

private slots:
    void on_pushButton_send_clicked();
    void on_pushButton_load_clicked();
};

#endif // MAINWINDOW_H
