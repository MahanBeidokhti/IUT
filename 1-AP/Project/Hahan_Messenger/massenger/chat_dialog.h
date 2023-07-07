#ifndef CHAT_DIALOG_H
#define CHAT_DIALOG_H

#include <QDialog>

namespace Ui {
class chat_Dialog;
}

class chat_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chat_Dialog(QWidget *parent = nullptr);
    ~chat_Dialog();

private:
    Ui::chat_Dialog *ui;
};

#endif // CHAT_DIALOG_H
