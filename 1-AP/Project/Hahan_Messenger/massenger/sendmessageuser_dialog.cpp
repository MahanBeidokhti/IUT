#include "sendmessageuser_dialog.h"
#include "ui_sendmessageuser_dialog.h"
#include <string>

using namespace std;

sendmessageuser_Dialog::sendmessageuser_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendmessageuser_Dialog)
{
    ui->setupUi(this);
    ui->chat_groupBox->hide();
    ap = new API(("http://api.barafardayebehtar.ml:8080"));
    ui->message_textEdit->setReadOnly(true);

}

sendmessageuser_Dialog::~sendmessageuser_Dialog()
{
    delete ui;
}

void sendmessageuser_Dialog::on_confirm_pushButton_clicked()
{
   QString username = ui->username_lineEdit->text();
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
   connect(ap,&API::UCG_Succ,this,&::sendmessageuser_Dialog::UserChatLoader);
   connect(ap,&API::UCG_Fail,this,&::sendmessageuser_Dialog::UserChatError);
   ui->chat_groupBox->show();
   ui->username_groupBox->close();

   timer = new QTimer();
   timer->setInterval(10000);
   timer->start();
   connect(timer,&QTimer::timeout,this,&::sendmessageuser_Dialog::Updater);


}


void sendmessageuser_Dialog::on_back_pushButton_clicked()
{
   close();
}

void sendmessageuser_Dialog::on_back_chat_pushButton_clicked()
{
    ui->chat_groupBox->close();
    ui->username_groupBox->show();
}

void sendmessageuser_Dialog::UserChatLoader(QByteArray *data)
{
     ui->name_label->setText(ui->username_lineEdit->text());
     QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
     QJsonObject JV = JAnswer.object();
     QString code =  JV.value("code").toString();
     qDebug()<< code;
     QString filename = ui->username_lineEdit->text() + "_chat.json" ;
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

            qDebug() << QString::fromStdString(msg);
            int b = stoi(a);


           for( int i = 0 ; i < b ; i++){
              QString blck = QString::fromStdString("block " + to_string(i));
              QString message = JV.value(blck).toObject().value("src").toString() + " : " + JV.value(blck).toObject().value("body").toString() + "(" + JV.value(blck).toObject().value("date").toString() + ")\n";

              ui->message_textEdit->append(message);
           }
      }

}

void sendmessageuser_Dialog::UserChatError(QNetworkReply *rep)
{
    qDebug()<<rep->errorString();
    ui->name_label->setText(ui->username_lineEdit->text() + "(offline)" );
    QJsonDocument JAnswer;
    QJsonObject JV;

    QString filename = ui->username_lineEdit->text() + "_chat.json" ;
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

void sendmessageuser_Dialog::on_send_pushButton_clicked()
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

    ap->sendMessage(ui->send_lineEdit->text(),ui->username_lineEdit->text(),token,"user");
    connect(ap,&API::Send_UCG_Succ,this,&::sendmessageuser_Dialog::UserSendLoader);
    connect(ap,&API::Send_UCG_Fail,this,&::sendmessageuser_Dialog::UserSendError);

    ui->send_lineEdit->clear();
}

void sendmessageuser_Dialog::UserSendLoader(QByteArray *data)
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
    ap->chatload(ui->username_lineEdit->text(),token,"user");
    connect(ap,&API::UCG_Succ,this,&::sendmessageuser_Dialog::UserChatLoader);
    connect(ap,&API::UCG_Fail,this,&::sendmessageuser_Dialog::UserChatError);
}

void sendmessageuser_Dialog::UserSendError(QNetworkReply *rep)
{
    qDebug()<<rep->errorString();
}

void sendmessageuser_Dialog::Updater()
{
    QString username = ui->username_lineEdit->text();
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
    connect(ap,&API::UCG_Succ,this,&::sendmessageuser_Dialog::UserChatLoader);
    connect(ap,&API::UCG_Fail,this,&::sendmessageuser_Dialog::UserChatError);
}
