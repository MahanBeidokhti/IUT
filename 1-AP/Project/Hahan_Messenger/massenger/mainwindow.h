#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "api.h"
#include "chat_dialog.h"
#include "menu_dialog.h"
#include <QEventLoop>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bottom_sign_page_clicked();
    void on_bottom_log_page_clicked();
    void on_Button_back_log_clicked();
    void on_Button_back_sign_clicked();
    //reading data and saving to file
    void reader(QByteArray *data);
    void errorer(QNetworkReply *rep);
    void on_bottom_sign_clicked();
    void on_bottom_log_clicked();

private:
    Ui::MainWindow *ui;
    menu_Dialog *menu_dialog;
    API *ap;

};
#endif // MAINWINDOW_H
