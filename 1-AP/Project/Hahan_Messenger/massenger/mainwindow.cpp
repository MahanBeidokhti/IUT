#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // hide
    ui->Login_Box->hide();
    ui->Signin_Box->hide();
    ui->log_error->hide();
    ui->sign_error->hide();
    //centeral alignments
    ui->Signin_Box->setAlignment(Qt::AlignHCenter);
    ui->Login_Box->setAlignment(Qt::AlignHCenter);
    ui->main_box->setAlignment(Qt::AlignHCenter);
    ap = new API("http://api.barafardayebehtar.ml:8080");
    //use of reader if login or sign in was successful
    connect(ap,&API::NoError,this,&::MainWindow::reader);
    //use of errorer if login or signin was failed
    connect(ap,&API::Error,this,&::MainWindow::errorer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bottom_sign_page_clicked()
{
    //show signin page
    ui->main_box->hide();
    ui->Signin_Box->show();
}


void MainWindow::on_bottom_log_page_clicked()
{
    //show login page
    ui->main_box->hide();
    ui->Login_Box->show();
}

void MainWindow::on_Button_back_sign_clicked()
{
    ui->Signin_Box->hide();
    ui->main_box->show();
}

void MainWindow::on_Button_back_log_clicked()
{
    ui->Login_Box->hide();
    ui->main_box->show();
}

void MainWindow::reader(QByteArray *data)
{
    QJsonDocument JAnswer = QJsonDocument::fromJson(*data);
    QJsonObject JV = JAnswer.object();
    QString code =  JV.value("code").toString();
    QString message =JV.value("message").toString();
    qDebug()<<code;
    if(code == "200")
    {
        if(message=="Logged in Successfully")
        {
            ui->log_error->setStyleSheet("QLabel {color = green;}");
            menu_dialog = new menu_Dialog();
            this->hide();
            menu_dialog->show();
            //file
            QFile tokenFile("token.txt");
            QString token = JV.value("token").toString();
            if (!tokenFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
               qDebug()<<"file cant be open";
            }
            else{
                QTextStream stream(&tokenFile);
                stream<<token;
            }
        }
        else if(message == "Signed Up Successfully")
        {
            ui->sign_error->setStyleSheet("QLabel {color = green;}");
            ui->Signin_Box->hide();
            ui->main_box->show();
            ui->input_username_sign->clear();
            ui->input_password_sign->clear();
            ui->input_firstname->clear();
            ui->input_lastname->clear();
        }
    }
    else
    {
        ui->log_error->setStyleSheet("QLabel {color = red;}");
    }
    ui->sign_error->setText(message);
    ui->sign_error->show();
    ui->log_error->setText(message);
    ui->log_error->show();
}

void MainWindow::errorer(QNetworkReply *rep)
{
    ui->log_error->setText(rep->errorString());
    ui->log_error->show();
    ui->sign_error->setText(rep->errorString());
    ui->sign_error->show();
}

void MainWindow::on_bottom_sign_clicked() //if signin succesfully
{
    QString usrnm = ui->input_username_sign->text();
    QString pswrd = ui->input_password_sign->text();
    QString fname = ui->input_firstname->text();
    QString lname = ui->input_lastname->text();
    if( usrnm.isEmpty() || pswrd.isEmpty())
    {
        ui->sign_error->setText("username or password is empty");
        ui->sign_error->show();
    }
    ap->sign(usrnm,pswrd,fname,lname);
    ui->input_username_log->clear();
    ui->input_password_log->clear();
    ui->input_firstname->clear();
    ui->input_lastname->clear();
}


void MainWindow::on_bottom_log_clicked() //if login succesfully
{
    QString usrnm = ui->input_username_log->text();
    QString pswrd = ui->input_password_log->text();
    QFile userpassFile("userpath.txt");
       if (!userpassFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
           qDebug()<<"file cant be open";
       }
       else{
           QTextStream stream(&userpassFile);
           stream << usrnm << "\n";
           stream << pswrd << "\n";
           userpassFile.close();
       }
    ap->log(usrnm,pswrd);
    ui->input_username_log->clear();
    ui->input_password_log->clear();
}

