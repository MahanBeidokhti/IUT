#ifndef SENDMESSAGECHANNEL_DIALOG_H
#define SENDMESSAGECHANNEL_DIALOG_H

#include <QDialog>
#include "api.h"
#include <QFile>
#include <QTextStream>


namespace Ui {
class sendmessagechannel_Dialog;
}

class sendmessagechannel_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit sendmessagechannel_Dialog(QWidget *parent = nullptr);
    ~sendmessagechannel_Dialog();

private slots:
    void on_confirm_pushButton_clicked();
    void on_back_pushButton_clicked();
    void on_back_chat_pushButton_clicked();
    void ChatLoader(QByteArray *data);
    void ChatError(QNetworkReply *rep);
    void on_send_pushButton_clicked();
    void SendLoader(QByteArray *data);
    void SendError(QNetworkReply *rep);

private:
    Ui::sendmessagechannel_Dialog *ui;
    API *ap;
};

#endif // SENDMESSAGECHANNEL_DIALOG_H
