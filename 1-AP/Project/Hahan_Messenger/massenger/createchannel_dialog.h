#ifndef CREATECHANNEL_DIALOG_H
#define CREATECHANNEL_DIALOG_H

#include <QDialog>
#include "api.h"
#include <QFile>
#include <QTextStream>


namespace Ui {
class createchannel_Dialog;
}

class createchannel_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit createchannel_Dialog(QWidget *parent = nullptr);
    ~createchannel_Dialog();

private slots:
    void on_confirm_pushButton_clicked();
    void on_back_pushButton_clicked();
    void succ_handler(QByteArray *data);
    void fail_handler(QNetworkReply *rep);

private:
    Ui::createchannel_Dialog *ui;
    API *ap;
};

#endif // CREATECHANNEL_DIALOG_H
