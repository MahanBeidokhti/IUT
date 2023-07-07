#ifndef JOINCHANNEL_DIALOG_H
#define JOINCHANNEL_DIALOG_H

#include <QDialog>
#include "api.h"
#include <QFile>
#include <QTextStream>


namespace Ui {
class joinchannel_Dialog;
}

class joinchannel_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit joinchannel_Dialog(QWidget *parent = nullptr);
    ~joinchannel_Dialog();

private slots:
    void on_confirm_pushButton_clicked();
    void on_back_pushButton_clicked();
    void succ_handler(QByteArray *data);
    void fail_handler(QNetworkReply *rep);

private:
    Ui::joinchannel_Dialog *ui;
    API *ap;

};

#endif // JOINCHANNEL_DIALOG_H
