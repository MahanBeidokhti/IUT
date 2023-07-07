#ifndef JOINGROUP_DIALOG_H
#define JOINGROUP_DIALOG_H

#include <QDialog>
#include "api.h"
#include <QFile>
#include <QTextStream>


namespace Ui {
class joingroup_Dialog;
}

class joingroup_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit joingroup_Dialog(QWidget *parent = nullptr);
    ~joingroup_Dialog();

private slots:
    void on_confirm_pushButton_clicked();
    void on_back_pushButton_clicked();
    void succ_handler(QByteArray *data);
    void fail_handler(QNetworkReply *rep);

private:
    Ui::joingroup_Dialog *ui;
    API *ap;
};

#endif // JOINGROUP_DIALOG_H
