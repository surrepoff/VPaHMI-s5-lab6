#ifndef BESSONOV_MIHEEV_H
#define BESSONOV_MIHEEV_H

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
class bessonov_miheev;
}

class bessonov_miheev : public QWidget
{
    Q_OBJECT

public:
    explicit bessonov_miheev(QWidget *parent = 0);
    ~bessonov_miheev();

private:
    Ui::bessonov_miheev *ui;

public slots:
    void recieveData(QString str);

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // BESSONOV_MIHEEV_H
