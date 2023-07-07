#include "getchannellist_dialog.h"
#include "ui_getchannellist_dialog.h"
#include <string>

using namespace std;

getchannellist_Dialog::getchannellist_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getchannellist_Dialog)
{
    ui->setupUi(this);
    ui->channel_list_textEdit->setReadOnly(true);

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
    ap->list(tok,"channel");
    connect(ap,&API::list_C_Succ,this,&::getchannellist_Dialog::succ_handler);
    connect(ap,&API::list_C_Fail,this,&::getchannellist_Dialog::fail_handler);
}

getchannellist_Dialog::~getchannellist_Dialog()
{
    delete ui;
}

void getchannellist_Dialog::on_channel_pushButton_clicked()
{
    hide();
}

void getchannellist_Dialog::succ_handler(QByteArray *data)
{
    QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
    QJsonObject JV = JAnswer.object();
    QString code =  JV.value("code").toString();
    qDebug()<< code;
    QString filename = "C_list.json" ;
    QFile messageFile(filename);
    if (!messageFile.open(QIODevice::WriteOnly)) {
         qDebug()<<"file cant be open";
     }
     else{

          messageFile.write(JAnswer.toJson());
          messageFile.close();
          ui->channel_list_textEdit->clear();

          string msg = JV.value("message").toString().toStdString();
          string a;
          for( int i = 12 ; msg[i] != '-' ; i++)
               a += msg[i];

           int b = stoi(a);


          for( int i = 0 ; i < b ; i++){
             QString blck = QString::fromStdString("block " + to_string(i));
             QString message = JV.value(blck).toObject().value("channel_name").toString();

             ui->channel_list_textEdit->append(message);
          }
     }
}

void getchannellist_Dialog::fail_handler(QNetworkReply* rep)
{
    qDebug()<<rep->errorString();
    QJsonDocument JAnswer;
    QJsonObject JV;
    QString filename = "C_list.json" ;
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
            for( int i = 12 ; msg[i] != '-' ; i++)
                a += msg[i];

             int b = stoi(a);


            for( int i = 0 ; i < b ; i++){
              QString blck = QString::fromStdString("block " + to_string(i));
              QString message = JV.value(blck).toObject().value("channel_name").toString();

              ui->channel_list_textEdit->append(message);
            }
      }
}
