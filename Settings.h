#ifndef SETTINGS_H
#define SETTINGS_H

#include <QVariant>
#include <QSettings>
#include <QMetaEnum>
#include <QSettings>
#include <QMetaEnum>
#include <QRegExp>
#include <QStringList>

class Settings
{
public:
    static void Init(const QString &file);

    static QString path;

    static QString license;

    static int minutes;
    static int silver_reward;

    static bool ip_address;
    static int  ip_address_limit;
    static int cultivation;
    static int level;
    static int hours_game;

    static QString gamedbd_host;
    static int gamedbd_port;

    static QString gdeliveryd_host;
    static int gdeliveryd_port;

    static QString mysql_host;
    static int mysql_port;
    static QString mysql_user;
    static QString mysql_pass;
    static QString mysql_db;
};

#endif // SETTINGS_H
