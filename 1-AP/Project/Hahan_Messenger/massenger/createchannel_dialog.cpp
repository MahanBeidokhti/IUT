#include "createchannel_dialog.h"
#include "ui_createchannel_dialog.h"

createchannel_Dialog::createchannel_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createchannel_Dialog)
{
    ap = new API("http://api.barafardayebehtar.ml:8080");
    ui->setupUi(this);
}

createchannel_Dialog::~createchannel_Dialog()
{
    delete ui;
}

void createchannel_Dialog::on_confirm_pushButton_clicked()
{
    QString channelname = ui->channelname_lineEdit->text();
    QString channeltitle = ui->channeltitle_lineEdit->text();
    if (channelname.isEmpty())
    {
        ui->error_label->setText("channel name can't be empty!");
    }
    else
    {
        QString token;
        QFile tokenFile("token.txt");
        if (!tokenFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
           qDebug()<<"file cant be open";
        }
        else{
            QTextStream stream(&tokenFile);
            stream>>token;
        }        ap->creator(token, channelname, channeltitle, "channel");
        connect(ap,&API::Creat_C_Succ,this,&::createchannel_Dialog::succ_handler);
        connect(ap,&API::Creat_C_Fail,this,&::createchannel_Dialog::fail_handler);
    }
}


void createchannel_Dialog::on_back_pushButton_clicked()
{
    close();
}

void createchannel_Dialog::succ_handler(QByteArray *data)
{
    QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
    QJsonObject JV = JAnswer.object();
    QString code =  JV.value("code").toString();
    qDebug()<< code;
    close();
}

void createchannel_Dialog::fail_handler(QNetworkReply *rep)
{
    ui->error_label->setText(rep->errorString());
}
