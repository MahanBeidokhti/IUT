#ifndef CREATEGROUP_DIALOG_H
#define CREATEGROUP_DIALOG_H

#include <QDialog>
#include "api.h"
#include <QFile>
#include <QTextStream>


namespace Ui {
class creategroup_Dialog;
}

class creategroup_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit creategroup_Dialog(QWidget *parent = nullptr);
    ~creategroup_Dialog();

private slots:
    void on_confirm_pushButton_clicked();
    void on_back_pushButton_clicked();
    void succ_handler(QByteArray *data);
    void fail_handler(QNetworkReply *rep);

private:
    Ui::creategroup_Dialog *ui;
    API *ap;
};

#endif // CREATEGROUP_DIALOG_H
