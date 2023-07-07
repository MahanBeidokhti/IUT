QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    api.cpp \
    createchannel_dialog.cpp \
    creategroup_dialog.cpp \
    getchannellist_dialog.cpp \
    getgrouplist_dialog.cpp \
    getuserlist_dialog.cpp \
    joinchannel_dialog.cpp \
    joingroup_dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    menu_dialog.cpp \
    sendmessagechannel_dialog.cpp \
    sendmessagegroup_dialog.cpp \
    sendmessageuser_dialog.cpp

HEADERS += \
    api.h \
    createchannel_dialog.h \
    creategroup_dialog.h \
    getchannellist_dialog.h \
    getgrouplist_dialog.h \
    getuserlist_dialog.h \
    joinchannel_dialog.h \
    joingroup_dialog.h \
    mainwindow.h \
    menu_dialog.h \
    sendmessagechannel_dialog.h \
    sendmessagegroup_dialog.h \
    sendmessageuser_dialog.h

FORMS += \
    createchannel_dialog.ui \
    creategroup_dialog.ui \
    getchannellist_dialog.ui \
    getgrouplist_dialog.ui \
    getuserlist_dialog.ui \
    joinchannel_dialog.ui \
    joingroup_dialog.ui \
    mainwindow.ui \
    menu_dialog.ui \
    sendmessagechannel_dialog.ui \
    sendmessagegroup_dialog.ui \
    sendmessageuser_dialog.ui

RESOURCES += \
    RS.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
