#ifndef MENU_DIALOG_H
#define MENU_DIALOG_H

#include <QDialog>
#include "sendmessageuser_dialog.h"
#include "sendmessagegroup_dialog.h"
#include "sendmessagechannel_dialog.h"
#include "creategroup_dialog.h"
#include "createchannel_dialog.h"
#include "joingroup_dialog.h"
#include "joinchannel_dialog.h"
#include "getuserlist_dialog.h"
#include "getgrouplist_dialog.h"
#include "getchannellist_dialog.h"




namespace Ui {
class menu_Dialog;
}

class menu_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit menu_Dialog(QWidget *parent = nullptr);
    ~menu_Dialog();

private slots:
    void on_SMS_user_pushButton_clicked();

    void on_SMS_group_pushButton_clicked();

    void on_SMS_channel_pushButton_clicked();

    void on_creategroup_pushButton_clicked();

    void on_createchannel_pushButton_clicked();

    void on_joingroup_pushButton_clicked();

    void on_joinchannel_pushButton_clicked();

    void on_getuserlist_pushButton_clicked();

    void on_getgrouplist_pushButton_clicked();

    void on_getchannellist_pushButton_clicked();

    void on_logout_pushButton_clicked();

private:
    Ui::menu_Dialog *ui;
    sendmessageuser_Dialog *sendMessageUser_dialog;
    sendmessagegroup_Dialog *sendMessageGroup_dialog;
    sendmessagechannel_Dialog *sendMessageChannel_dialog;
    creategroup_Dialog *creategroup_dialog;
    createchannel_Dialog *createchannel_dialog;
    joingroup_Dialog *joingroup_dialog;
    joinchannel_Dialog *joinchannel_dialog;
    getuserlist_Dialog *getuserlist_dialog;
    getgrouplist_Dialog *getgrouplist_dialog;
    getchannellist_Dialog *getchannellist_dialog;
};

#endif // MENU_DIALOG_H
