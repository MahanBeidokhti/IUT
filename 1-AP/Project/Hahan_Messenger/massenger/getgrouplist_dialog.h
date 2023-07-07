#ifndef GETGROUPLIST_DIALOG_H
#define GETGROUPLIST_DIALOG_H

#include <QDialog>
#include "api.h"
#include <QFile>
#include <QTextStream>


namespace Ui {
class getgrouplist_Dialog;
}

class getgrouplist_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit getgrouplist_Dialog(QWidget *parent = nullptr);
    ~getgrouplist_Dialog();

private slots:
    void on_group_pushButton_clicked();
    void succ_handler(QByteArray *data);
    void fail_handler(QNetworkReply* rep);

private:
    Ui::getgrouplist_Dialog *ui;
    API *ap;
};

#endif // GETGROUPLIST_DIALOG_H
