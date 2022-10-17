#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myform = new bessonov_miheev();

    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(show()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_send_clicked()));
    connect(this, SIGNAL(sendData(QString)), myform, SLOT(recieveData(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_load_clicked()
{
    QString filename = QFileDialog::getOpenFileName(nullptr, "Выберите изображение", QDir::currentPath(), "*.png *.jpg *.gif *.jpeg");
    ui->lineEdit_path->setText(filename);
    QImage image1(filename);
    ui->label_photo->setPixmap(QPixmap::fromImage(image1));
}

void MainWindow::on_pushButton_send_clicked()
{
    if (ui->lineEdit_fio->text() == "" or ui->lineEdit_path->text() == "" or ui->lineEdit_dol->text() == "" or ui->lineEdit_char->text() == "") {
        QMessageBox::information(this, "Заполните все поля", "Заполните все поля, прежде чем продолжить");
        return;
    } else {
        this->myform->show();
    }
    QString st = ui->lineEdit_path->text() + "*" + ui->lineEdit_fio->text() +
            "\n" + ui->lineEdit_dol->text() + "\n" + ui->lineEdit_char->text() +
            "\n" + ui->dateEdit->text();
    if (ui->radioButton_m->isChecked() == true) {
        st += "\nпол мужской";
    } else {
        st += "\nпол женский";
    }
    emit sendData(st);
}
