#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w_main;
    menu_Dialog w_menu;

    QFile tokenFile("token.txt");

     if(tokenFile.size() > 0)
           w_menu.show();
      else
           w_main.show();


    return a.exec();
}
