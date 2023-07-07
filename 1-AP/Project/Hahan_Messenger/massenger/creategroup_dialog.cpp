#include "creategroup_dialog.h"
#include "ui_creategroup_dialog.h"

creategroup_Dialog::creategroup_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::creategroup_Dialog)
{
    ap = new API("http://api.barafardayebehtar.ml:8080");
    ui->setupUi(this);
}

creategroup_Dialog::~creategroup_Dialog()
{
    delete ui;
}

void creategroup_Dialog::on_confirm_pushButton_clicked()
{
    QString groupname = ui->groupname_lineEdit->text();
    QString grouptitle = ui->grouptitle_lineEdit->text();
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
        ap->creator(token, groupname, grouptitle, "group");
        connect(ap,&API::Creat_G_Succ,this,&::creategroup_Dialog::succ_handler);
        connect(ap,&API::Creat_G_Fail,this,&::creategroup_Dialog::fail_handler);
    }
}


void creategroup_Dialog::on_back_pushButton_clicked()
{
    close();
}

void creategroup_Dialog::succ_handler(QByteArray *data)
{
    QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
    QJsonObject JV = JAnswer.object();
    QString code =  JV.value("code").toString();
    qDebug()<< code;
    close();
}

void creategroup_Dialog::fail_handler(QNetworkReply *rep)
{
    ui->error_label->setText(rep->errorString());
}
