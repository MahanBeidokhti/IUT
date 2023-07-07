#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>

class message
{
public:
    message();
    message(QString _body , QString _src, QString _dst, QString _date);
    QString body;
    QString src;
    QString dst;
    QString date;
};

#endif // MESSAGE_H
