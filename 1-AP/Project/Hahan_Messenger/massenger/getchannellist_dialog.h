#ifndef GETCHANNELLIST_DIALOG_H
#define GETCHANNELLIST_DIALOG_H

#include <QDialog>
#include "api.h"
#include <QFile>
#include <QTextStream>


namespace Ui {
class getchannellist_Dialog;
}

class getchannellist_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit getchannellist_Dialog(QWidget *parent = nullptr);
    ~getchannellist_Dialog();

private slots:
    void on_channel_pushButton_clicked();
    void succ_handler(QByteArray *data);
    void fail_handler(QNetworkReply* rep);

private:
    Ui::getchannellist_Dialog *ui;
    API *ap;
};

#endif // GETCHANNELLIST_DIALOG_H
