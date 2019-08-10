QT = core sql network
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Database.cpp \
        Network/Daemon.cpp \
        Network/OctetsStream.cpp \
        Packets/DBGetConsumeInfosArg.cpp \
        Packets/DBGetConsumeInfosRes.cpp \
        Packets/GMListOnlineUser.cpp \
        Packets/GMListOnlineUserRes.cpp \
        Packets/GetRoleStatusArg.cpp \
        Packets/GetRoleStatusRes.cpp \
        Server.cpp \
        Settings.cpp \
        Thread.cpp \
        Utils.cpp \
        Worker.cpp \
        hrnsxnxpqw.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Database.h \
    Models/GMPlayerInfo.h \
    Models/GRoleStatus.h \
    Models/PlayerConsumeInfo.h \
    Network/Daemon.h \
    Network/Octets.h \
    Network/OctetsStream.h \
    Packets/DBGetConsumeInfosArg.h \
    Packets/DBGetConsumeInfosRes.h \
    Packets/GMListOnlineUser.h \
    Packets/GMListOnlineUserRes.h \
    Packets/GetRoleStatusArg.h \
    Packets/GetRoleStatusRes.h \
    Server.h \
    Settings.h \
    Thread.h \
    Utils.h \
    Worker.h \
    hrnsxnxpqw.h

#QMAKE_LFLAGS += -static-libstdc++ -static-libgcc -static
