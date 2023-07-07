#ifndef API_H
#define API_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

class API : public QObject
{
    Q_OBJECT
public:
    //constructor
    explicit API(const QString &Host, QObject *parent = nullptr);
    //sending sign in command to server and gathering the results
    void sign(const QString &username ,const QString &password ,const QString &Fname,const QString &Lname);
    //sending Log in command to server and gathering the results
    void log(const QString &username ,const QString &password);
    //getting user chats
    void chatload(const QString &username, const QString &token, const QString &type);
    //sending user message
    void sendMessage(const QString &body, const QString &username,const QString &token, const QString &type);
    //creating channel and group
    void creator(const QString &token, const QString &name, const QString &title, const QString &type);
    //joining channel and group
    void joiner(const QString &token, const QString &name, const QString &type);
    //UGC list reciever
    void list(const QString &token, const QString &type);
signals:
    //signal for situation wich one of the log or sign commands are corrupted
    void NoError(QByteArray* data);
    //signal of a situation wich there is no error and you want to use the response of the server
    void Error(QNetworkReply* data);
    //UserChannelGroupe successful/fail
    void UCG_Succ(QByteArray* data);
    void UCG_Fail(QNetworkReply* data);
    //Sending message to UCG
    void Send_UCG_Succ(QByteArray* data);
    void Send_UCG_Fail(QNetworkReply* data);
    //Sending message to C
    void Send_C_Succ(QByteArray* data);
    void Send_C_Fail(QNetworkReply* data);
    void C_Succ(QByteArray* data);
    void C_Fail(QNetworkReply* data);
    //Sending message to G
    void Send_G_Succ(QByteArray* data);
    void Send_G_Fail(QNetworkReply* data);
    void G_Succ(QByteArray* data);
    void G_Fail(QNetworkReply* data);
    //creator connection check
    void Creat_C_Succ(QByteArray *data);
    void Creat_C_Fail(QNetworkReply* data);
    void Creat_G_Succ(QByteArray *data);
    void Creat_G_Fail(QNetworkReply* data);
    //joiner connection check
    void join_G_Succ(QByteArray *data);
    void join_G_Fail(QNetworkReply* data);
    void join_C_Succ(QByteArray *data);
    void join_C_Fail(QNetworkReply* data);
    //list connection checker
    void list_U_Succ(QByteArray *data);
    void list_U_Fail(QNetworkReply* data);
    void list_G_Succ(QByteArray *data);
    void list_G_Fail(QNetworkReply* data);
    void list_C_Succ(QByteArray *data);
    void list_C_Fail(QNetworkReply* data);

private slots:
    //slot for gathering the server results
    void Gather();
    //slot for gathering data in getting messages list
    void GetChat_Gather();
    //slot for gathering data in sending message
    void SendChat_Gather();
    //slot for gathering data in sending message to group
    void SendChat_G_Gather();
    //slot for gathering data in sending message to channel
    void SendChat_C_Gather();
    void GetChat_G_Gather();
    void GetChat_C_Gather();
    //Group slot for gathering data in creating group
    void Creat_Gather_G();
    //channel slot for gathering data in creating channel
    void Creat_Gather_C();
    //Group slot for gathering data in joining group
    void join_Gather_G();
    //channel slot for gathering data in joining channel
    void join_Gather_C();
    //getting list of UGC
    void List_U_Gather();
    void List_G_Gather();
    void List_C_Gather();

private:
    //variable wich allows us to send request to the http server (api)
    QNetworkAccessManager* manager;
    //variable wich allows us to recieve the response from the http server (api)
    QNetworkReply* rep;
    //variable for storing the server responses
    QByteArray* data;
    //host name (api.barafardayebehtar.ml:8080)
    QString host;

};

#endif // API_H
