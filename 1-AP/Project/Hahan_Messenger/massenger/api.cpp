#include "api.h"

API::API(const QString &Host, QObject *parent)
    : QObject{parent}
{
    host = Host;
    manager = new QNetworkAccessManager(this);
    data = new QByteArray();
}

void API::sign(const QString &username,const  QString &password,const  QString &Fname,const  QString &Lname)
{

    QString command = host+"/signup?username="+username+"&password="+password;

    if(!Fname.isEmpty())
        command += "&firstname="+Fname;
    if(!Lname.isEmpty())
        command += "&lastname="+Lname;

    rep = manager->get(QNetworkRequest(QUrl(command)));
    connect(rep,&QNetworkReply::finished,this,&API::Gather);
}

void API::log(const QString &username ,const QString &password)
{
    QString command = host+"/login?username="+username+"&password="+password;
    rep = manager->get(QNetworkRequest(QUrl(command)));
    connect(rep,&QNetworkReply::finished,this,&API::Gather);
}

void API::chatload(const QString &username, const QString &token, const QString &type)
{
    QString command = host+"/get"+type+"chats?token="+token+"&dst="+username;
    rep = manager->get(QNetworkRequest(QUrl(command)));
    if(type == "user")
    {
        connect(rep,&QNetworkReply::finished,this,&API::GetChat_Gather);
    }
    else if(type == "group")
    {
        connect(rep,&QNetworkReply::finished,this,&API::GetChat_G_Gather);
    }
    else
    {
        connect(rep,&QNetworkReply::finished,this,&API::GetChat_C_Gather);
    }
}

void API::sendMessage(const QString &body, const QString &username,const QString &token, const QString &type)
{
    QString command = host+"/sendmessage"+type+"?token="+token+"&dst="+username+"&body="+body;
    rep = manager->get(QNetworkRequest(QUrl(command)));
    if(type == "user")
    {
        connect(rep,&QNetworkReply::finished,this,&API::SendChat_Gather);
    }
    else if(type == "group")
    {
        connect(rep,&QNetworkReply::finished,this,&API::SendChat_G_Gather);
    }
    else
    {
        connect(rep,&QNetworkReply::finished,this,&API::SendChat_C_Gather);
    }
}

void API::creator(const QString &token, const QString &name, const QString &title, const QString &type)
{
    QString command = host+"/create"+type+"?token="+token+"&"+type+"_name="+name+"&"+type+"_title="+title;
    rep = manager->get(QNetworkRequest(QUrl(command)));
    if (type == "group")
        connect(rep,&QNetworkReply::finished,this,&API::Creat_Gather_G);
    else
        connect(rep,&QNetworkReply::finished,this,&API::Creat_Gather_C);
}

void API::joiner(const QString &token, const QString &name, const QString &type)
{
    QString command = host+"/join"+type+"?token="+token+"&"+type+"_name="+name;
    qDebug()<<command;
    rep = manager->get(QNetworkRequest(QUrl(command)));
    if (type == "group")
        connect(rep,&QNetworkReply::finished,this,&API::join_Gather_G);
    else
        connect(rep,&QNetworkReply::finished,this,&API::join_Gather_C);
}

void API::list(const QString &token, const QString &type)
{
    QString command = host+"/get"+type+"list?token="+token;
    rep = manager->get(QNetworkRequest(QUrl(command)));
    if(type == "user")
    {
        connect(rep,&QNetworkReply::finished,this,&API::List_U_Gather);
    }
    else if(type == "group")
    {
        connect(rep,&QNetworkReply::finished,this,&API::List_G_Gather);
    }
    else
    {
        connect(rep,&QNetworkReply::finished,this,&API::List_C_Gather);
    }
}

void API::Gather()
{
    //check if sending request was successful, read data.
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit NoError(data);
    }
    else
    {
        data = NULL;
        emit Error(rep);
    }
    rep->deleteLater();
}

void API::GetChat_Gather()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit UCG_Succ(data);
    }
    else
    {
        data = NULL;
        emit UCG_Fail(rep);
    }
    rep->deleteLater();
}
void API::GetChat_G_Gather()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit G_Succ(data);
    }
    else
    {
        data = NULL;
        emit G_Fail(rep);
    }
    rep->deleteLater();
}
void API::GetChat_C_Gather()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit C_Succ(data);
    }
    else
    {
        data = NULL;
        emit C_Fail(rep);
    }
    rep->deleteLater();
}


void API::SendChat_Gather()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit Send_UCG_Succ(data);
    }
    else
    {
        data = NULL;
        emit Send_UCG_Fail(rep);
    }
    rep->deleteLater();
}

void API::SendChat_G_Gather()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit Send_G_Succ(data);
    }
    else
    {
        data = NULL;
        emit Send_G_Fail(rep);
    }
    rep->deleteLater();
}

void API::SendChat_C_Gather()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit Send_C_Succ(data);
    }
    else
    {
        data = NULL;
        emit Send_C_Fail(rep);
    }
    rep->deleteLater();
}

void API::Creat_Gather_G()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit Creat_G_Succ(data);
    }
    else
    {
        data = NULL;
        emit Creat_G_Fail(rep);
    }
    rep->deleteLater();
}

void API::Creat_Gather_C()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit Creat_C_Succ(data);
    }
    else
    {
        data = NULL;
        emit Creat_C_Fail(rep);
    }
    rep->deleteLater();
}

void API::join_Gather_G()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit join_G_Succ(data);
    }
    else
    {
        data = NULL;
        emit join_G_Fail(rep);
    }
    rep->deleteLater();
}

void API::join_Gather_C()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit join_C_Succ(data);
    }
    else
    {
        data = NULL;
        emit join_C_Fail(rep);
    }
    rep->deleteLater();
}

void API::List_U_Gather()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit list_U_Succ(data);
    }
    else
    {
        data = NULL;
        emit list_U_Fail(rep);
    }
    rep->deleteLater();
}

void API::List_G_Gather()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit list_G_Succ(data);
    }
    else
    {
        data = NULL;
        emit list_G_Fail(rep);
    }
    rep->deleteLater();
}

void API::List_C_Gather()
{
    if(rep->error()==QNetworkReply::NoError)
    {
        *data = rep->readAll();
        emit list_C_Succ(data);
    }
    else
    {
        data = NULL;
        emit list_C_Fail(rep);
    }
    rep->deleteLater();
}
