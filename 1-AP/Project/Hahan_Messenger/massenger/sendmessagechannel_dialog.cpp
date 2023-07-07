#include "sendmessagechannel_dialog.h"
#include "ui_sendmessagechannel_dialog.h"
#include <string>

using namespace std;

sendmessagechannel_Dialog::sendmessagechannel_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendmessagechannel_Dialog)
{
    ui->setupUi(this);
    ui->chat_groupBox->hide();
    ap = new API(("http://api.barafardayebehtar.ml:8080"));
    ui->message_textEdit->setReadOnly(true);
}

sendmessagechannel_Dialog::~sendmessagechannel_Dialog()
{
    delete ui;
}

void sendmessagechannel_Dialog::on_confirm_pushButton_clicked()
{
    QString username = ui->name_lineEdit->text();
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
    ap->chatload(username,tok,"channel");
    connect(ap,&API::C_Succ,this,&::sendmessagechannel_Dialog::ChatLoader);
    connect(ap,&API::C_Fail,this,&::sendmessagechannel_Dialog::ChatError);
    ui->chat_groupBox->show();
    ui->channelname_groupBox->close();

}


void sendmessagechannel_Dialog::on_back_pushButton_clicked()
{
    close();
}


void sendmessagechannel_Dialog::on_back_chat_pushButton_clicked()
{
    ui->chat_groupBox->hide();
    ui->channelname_groupBox->show();
}

void sendmessagechannel_Dialog::ChatLoader(QByteArray *data)
{
     ui->name_label->setText(ui->name_lineEdit->text());
     QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
     QJsonObject JV = JAnswer.object();
     QString code =  JV.value("code").toString();
     qDebug()<< code;
     QString filename = ui->name_lineEdit->text() + "_chat.json" ;
     QFile messageFile(filename);
     if (!messageFile.open(QIODevice::WriteOnly)) {
          qDebug()<<"file cant be open";
      }
      else{

           messageFile.write(JAnswer.toJson());
           messageFile.close();
           ui->message_textEdit->clear();

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

void sendmessagechannel_Dialog::ChatError(QNetworkReply *rep)
{
    qDebug() << rep->errorString();
    ui->name_label->setText(ui->name_lineEdit->text() + "(offline)" );
    QJsonDocument JAnswer;
    QJsonObject JV;

    QString filename = ui->name_lineEdit->text() + "_chat.json" ;
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

void sendmessagechannel_Dialog::on_send_pushButton_clicked()
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

    ap->sendMessage(ui->send_lineEdit->text(),ui->name_lineEdit->text(),token,"channel");
    connect(ap,&API::Send_C_Succ,this,&::sendmessagechannel_Dialog::SendLoader);
    connect(ap,&API::Send_C_Fail,this,&::sendmessagechannel_Dialog::SendError);

    ui->send_lineEdit->clear();
}

void sendmessagechannel_Dialog::SendLoader(QByteArray *data)
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

    if(message=="You are not Admin of This Channel")
    {
        ui->send_lineEdit->setStyleSheet("color: red;");
        ui->send_lineEdit->setText(message);
        ui->send_lineEdit->setReadOnly(true);
    }

    ap = new API(("http://api.barafardayebehtar.ml:8080"));
    ap->chatload(ui->name_lineEdit->text(),token,"channel");
    connect(ap,&API::C_Succ,this,&::sendmessagechannel_Dialog::ChatLoader);
    connect(ap,&API::C_Fail,this,&::sendmessagechannel_Dialog::ChatError);
}

void sendmessagechannel_Dialog::SendError(QNetworkReply *rep)
{
    qDebug()<<rep->errorString();

}
