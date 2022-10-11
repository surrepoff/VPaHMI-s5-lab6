#include "bessonov_miheev.h"
#include "ui_bessonov_miheev.h"

bessonov_miheev::bessonov_miheev(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::bessonov_miheev)
{
    ui->setupUi(this);
}

bessonov_miheev::~bessonov_miheev()
{
    delete ui;
}
