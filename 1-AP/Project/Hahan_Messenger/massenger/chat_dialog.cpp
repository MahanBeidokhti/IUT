#include "chat_dialog.h"
#include "ui_chat_dialog.h"

chat_Dialog::chat_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat_Dialog)
{
    ui->setupUi(this);
}

chat_Dialog::~chat_Dialog()
{
    delete ui;
}
