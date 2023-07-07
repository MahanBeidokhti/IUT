#include "getuserlist_dialog.h"
#include "ui_getuserlist_dialog.h"
#include <string>

using namespace std;

getuserlist_Dialog::getuserlist_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getuserlist_Dialog)
{
    ui->setupUi(this);
    ui->user_list_textEdit->setReadOnly(true);

    ap = new API(("http://api.barafardayebehtar.ml:8080"));
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
    ap->list(tok,"user");
    connect(ap,&API::list_U_Succ,this,&::getuserlist_Dialog::succ_handler);
    connect(ap,&API::list_U_Fail,this,&::getuserlist_Dialog::fail_handler);
}

getuserlist_Dialog::~getuserlist_Dialog()
{
    delete ui;
}

void getuserlist_Dialog::on_user_pushButton_clicked()
{
    hide();
}

void getuserlist_Dialog::succ_handler(QByteArray *data)
{
    QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
    QJsonObject JV = JAnswer.object();
    QString code =  JV.value("code").toString();
    qDebug()<< code;
    QString filename = "U_list.json" ;
    QFile messageFile(filename);
    if (!messageFile.open(QIODevice::WriteOnly)) {
         qDebug()<<"file cant be open";
     }
     else{

          messageFile.write(JAnswer.toJson());
          messageFile.close();
          ui->user_list_textEdit->clear();

          string msg = JV.value("message").toString().toStdString();
          string a;
          for( int i = 20 ; msg[i] != '-' ; i++)
               a += msg[i];

           qDebug()<< QString::fromStdString(msg);
           int b = stoi(a);


          for( int i = 0 ; i < b ; i++){
             QString blck = QString::fromStdString("block " + to_string(i));
             QString message = JV.value(blck).toObject().value("src").toString();

             ui->user_list_textEdit->append(message);
          }
     }
}

void getuserlist_Dialog::fail_handler(QNetworkReply* rep)
{
    qDebug()<<rep->errorString();
    QJsonDocument JAnswer;
    QJsonObject JV;
    QString filename = "U_list.json" ;
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
            for( int i = 20 ; msg[i] != '-' ; i++)
                a += msg[i];

             int b = stoi(a);


            for( int i = 0 ; i < b ; i++){
              QString blck = QString::fromStdString("block " + to_string(i));
              QString message = JV.value(blck).toObject().value("src").toString();
              ui->user_list_textEdit->append(message);
            }
      }
}
