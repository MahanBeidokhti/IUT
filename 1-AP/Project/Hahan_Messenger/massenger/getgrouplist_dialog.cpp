#include "getgrouplist_dialog.h"
#include "ui_getgrouplist_dialog.h"
#include <string>

using namespace std;

getgrouplist_Dialog::getgrouplist_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getgrouplist_Dialog)
{
    ui->setupUi(this);
    ui->group_list_textEdit->setReadOnly(true);

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
    ap->list(tok,"group");
    connect(ap,&API::list_G_Succ,this,&::getgrouplist_Dialog::succ_handler);
    connect(ap,&API::list_G_Fail,this,&::getgrouplist_Dialog::fail_handler);
}

getgrouplist_Dialog::~getgrouplist_Dialog()
{
    delete ui;
}

void getgrouplist_Dialog::on_group_pushButton_clicked()
{
    hide();
}

void getgrouplist_Dialog::succ_handler(QByteArray *data)
{
    QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
    QJsonObject JV = JAnswer.object();
    QString code =  JV.value("code").toString();
    qDebug()<< code;
    QString filename = "G_list.json" ;
    QFile messageFile(filename);
    if (!messageFile.open(QIODevice::WriteOnly)) {
         qDebug()<<"file cant be open";
     }
     else{

          messageFile.write(JAnswer.toJson());
          messageFile.close();
          ui->group_list_textEdit->clear();

          string msg = JV.value("message").toString().toStdString();
          string a;
          for( int i = 12 ; msg[i] != '-' ; i++)
               a += msg[i];

           int b = stoi(a);


          for( int i = 0 ; i < b ; i++){
             QString blck = QString::fromStdString("block " + to_string(i));
             QString message = JV.value(blck).toObject().value("group_name").toString();

             ui->group_list_textEdit->append(message);
          }
     }
}

void getgrouplist_Dialog::fail_handler(QNetworkReply* rep)
{
    qDebug()<<rep->errorString();
    QJsonDocument JAnswer;
    QJsonObject JV;
    QString filename = "G_list.json" ;
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
              QString message = JV.value(blck).toObject().value("group_name").toString();

              ui->group_list_textEdit->append(message);
            }
      }
}
