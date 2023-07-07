#include "sendmessagegroup_dialog.h"
#include "ui_sendmessagegroup_dialog.h"
#include <string>


using namespace std;

sendmessagegroup_Dialog::sendmessagegroup_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendmessagegroup_Dialog)
{
    ui->setupUi(this);
    ui->chat_groupBox->hide();
    ap = new API(("http://api.barafardayebehtar.ml:8080"));
    ui->message_textEdit->setReadOnly(true);

}

sendmessagegroup_Dialog::~sendmessagegroup_Dialog()
{
    delete ui;
}

void sendmessagegroup_Dialog::on_confirm_pushButton_clicked()
{
    QString username = ui->groupname_lineEdit->text();
    QString tok;
    QFile tokenFile("token.txt");
    if (!tokenFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
       qDebug()<<"file cant be open";
    }
    else
    {
        QTextStream stream(&tokenFile);
        stream>>tok;
    }
    ap->chatload(username,tok,"group");
    connect(ap,&API::G_Succ,this,&::sendmessagegroup_Dialog::ChatLoader);
    connect(ap,&API::G_Fail,this,&::sendmessagegroup_Dialog::ChatError);
    ui->chat_groupBox->show();
    ui->groupname_groupBox->close();

    timer = new QTimer();
    timer->setInterval(10000);
    timer->start();
    connect(timer,&QTimer::timeout,this,&::sendmessagegroup_Dialog::Updater);
}

void sendmessagegroup_Dialog::on_back_pushButton_clicked()
{
    close();
}

void sendmessagegroup_Dialog::on_back_chat_pushButton_clicked()
{
    ui->chat_groupBox->hide();
    ui->groupname_groupBox->show();
}

void sendmessagegroup_Dialog::ChatLoader(QByteArray *data)
{
     ui->name_label->setText(ui->groupname_lineEdit->text());
     QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
     QJsonObject JV = JAnswer.object();
     QString code =  JV.value("code").toString();
     qDebug()<< code;
     QString filename = ui->groupname_lineEdit->text() + "_chat.json" ;
     QFile messageFile(filename);
     if (!messageFile.open(QIODevice::WriteOnly)) {
          qDebug()<<"file cant be open";
      }
      else{

               string msg = JV.value("message").toString().toStdString();
               string a;
               for( int i = 11 ; msg[i] != '-' ; i++)
                      a += msg[i];

               int b = stoi(a);
               if(b!=0)
               {
                   messageFile.write(JAnswer.toJson());
                   messageFile.close();
                   ui->message_textEdit->clear();

                   for( int i = 0 ; i < b ; i++){
                      QString blck = QString::fromStdString("block " + to_string(i));
                      QString message = JV.value(blck).toObject().value("src").toString() + " : " + JV.value(blck).toObject().value("body").toString() + "(" + JV.value(blck).toObject().value("date").toString() + ")\n";

                      ui->message_textEdit->append(message);
               }

           }
      }

}

void sendmessagegroup_Dialog::ChatError(QNetworkReply *rep)
{
    qDebug()<<rep->errorString();
    ui->name_label->setText(ui->groupname_lineEdit->text() + "(offline)" );
    QJsonDocument JAnswer;
    QJsonObject JV;

    QString filename = ui->groupname_lineEdit->text() + "_chat.json" ;
    QFile messageFile(filename);
     if (!messageFile.open(QIODevice::ReadOnly) ) {
         qDebug()<<"file cant be open";
     }
     else{
           QByteArray jsonData = messageFile.readAll();
           JAnswer = QJsonDocument::fromJson(jsonData);
           JV = JAnswer.object();
           messageFile.close();

           string msg = JV.value("message").toString().toStdString();
           string a;
           for( int i = 11 ; msg[i] != '-' ; i++)
               a += msg[i];

           int b = stoi(a);

           for( int i = 0 ; i < b ; i++){
               QString blck = QString::fromStdString("block " + to_string(i));
               QString message = JV.value(blck).toObject().value("src").toString() + " : " + JV.value(blck).toObject().value("body").toString() + "(" + JV.value(blck).toObject().value("date").toString() + ")\n";

               ui->message_textEdit->append(message);
           }
     }
}

void sendmessagegroup_Dialog::on_send_pushButton_clicked()
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

    ap->sendMessage(ui->send_lineEdit->text(),ui->groupname_lineEdit->text(),token,"group");
    connect(ap,&API::Send_G_Succ,this,&::sendmessagegroup_Dialog::SendLoader);
    connect(ap,&API::Send_G_Fail,this,&::sendmessagegroup_Dialog::SendError);

    ui->send_lineEdit->clear();
}

void sendmessagegroup_Dialog::SendLoader(QByteArray *data)
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
    QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
    QJsonObject JV = JAnswer.object();
    QString code =  JV.value("code").toString();
    QString message = JV.value("message").toString();
    qDebug()<<code << "   code";
    qDebug()<<message << "    message";

    ap = new API(("http://api.barafardayebehtar.ml:8080"));
    ap->chatload(ui->groupname_lineEdit->text(),token,"group");
    connect(ap,&API::G_Succ,this,&::sendmessagegroup_Dialog::ChatLoader);
    connect(ap,&API::G_Fail,this,&::sendmessagegroup_Dialog::ChatError);
}

void sendmessagegroup_Dialog::SendError(QNetworkReply *rep)
{
    qDebug()<<rep->errorString();
}

void sendmessagegroup_Dialog::Updater()
{
    QString username = ui->groupname_lineEdit->text();
    QString tok;
    QFile tokenFile("token.txt");
    if (!tokenFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
       qDebug()<<"file cant be open";
    }
    else{
        QTextStream stream(&tokenFile);
        stream>>tok;
    }
    ap->chatload(username,tok,"user");
    connect(ap,&API::UCG_Succ,this,&::sendmessagegroup_Dialog::ChatLoader);
    connect(ap,&API::UCG_Fail,this,&::sendmessagegroup_Dialog::ChatError);
}
