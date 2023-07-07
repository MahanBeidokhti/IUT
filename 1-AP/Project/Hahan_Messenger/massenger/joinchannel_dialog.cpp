#include "joinchannel_dialog.h"
#include "ui_joinchannel_dialog.h"

joinchannel_Dialog::joinchannel_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joinchannel_Dialog)
{
    ui->setupUi(this);
    ap = new API("http://api.barafardayebehtar.ml:8080");
}

joinchannel_Dialog::~joinchannel_Dialog()
{
    delete ui;
}

void joinchannel_Dialog::on_confirm_pushButton_clicked()
{
    QString channelname = ui->channelname_lineEdit->text();
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
        }
        ap->joiner(token, channelname , "channel");
        connect(ap,&API::join_C_Succ,this,&::joinchannel_Dialog::succ_handler);
        connect(ap,&API::join_C_Fail,this,&::joinchannel_Dialog::fail_handler);
    }
}


void joinchannel_Dialog::on_back_pushButton_clicked()
{
    close();
}
void joinchannel_Dialog::succ_handler(QByteArray *data)
{
    QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
    QJsonObject JV = JAnswer.object();
    QString code =  JV.value("code").toString();
    qDebug()<< code;
    close();
}

void joinchannel_Dialog::fail_handler(QNetworkReply *rep)
{
    ui->error_label->setText(rep->errorString());
}


