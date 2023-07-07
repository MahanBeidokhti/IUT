#include "joingroup_dialog.h"
#include "ui_joingroup_dialog.h"

joingroup_Dialog::joingroup_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joingroup_Dialog)
{
    ui->setupUi(this);
    ap = new API("http://api.barafardayebehtar.ml:8080");
}

joingroup_Dialog::~joingroup_Dialog()
{
    delete ui;
}

void joingroup_Dialog::on_confirm_pushButton_clicked()
{
    QString groupname = ui->groupname_lineEdit->text();
    if (groupname.isEmpty())
    {
        ui->error_label->setText("group name can't be empty!");
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
        ap->joiner(token, groupname , "group");
        connect(ap,&API::join_G_Succ,this,&::joingroup_Dialog::succ_handler);
        connect(ap,&API::join_G_Fail,this,&::joingroup_Dialog::fail_handler);
    }
}


void joingroup_Dialog::on_back_pushButton_clicked()
{
    close();
}

void joingroup_Dialog::succ_handler(QByteArray *data)
{
    QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
    QJsonObject JV = JAnswer.object();
    QString code =  JV.value("code").toString();
    qDebug()<< code;
    close();
}

void joingroup_Dialog::fail_handler(QNetworkReply *rep)
{
    ui->error_label->setText(rep->errorString());
}



