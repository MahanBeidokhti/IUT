#include "message.h"


message::message()
{
    body = 0;
    src = 0;
    dst = 0;
    date = 0;
}

message::message(QString _body, QString _src, QString _dst, QString _date)
{
    body = _body;
    src = _src;
    dst = _dst;
    date = _date;
}
