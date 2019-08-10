#include "Settings.h"

QString Settings::path = "";
QString Settings::license = "";

int Settings::minutes = 60;
int Settings::silver_reward = 0;

bool Settings::ip_address =  false;
int  Settings::ip_address_limit = 0;
int  Settings::cultivation = 0;
int  Settings::level = 0;
int  Settings::hours_game = 0;

QString Settings::gamedbd_host = "";
int Settings::gamedbd_port = 0;

QString Settings::gdeliveryd_host = "";
int Settings::gdeliveryd_port = 0;

QString Settings::mysql_host = "";
int Settings::mysql_port = 0;
QString Settings::mysql_user = "";
QString Settings::mysql_pass = "";
QString Settings::mysql_db = "";

void Settings::Init(const QString &file)
{
    QSettings settings(file + "/goldtimer.conf", QSettings::IniFormat);

    path = file;

    license = settings.value("License/code").toString();

    minutes = settings.value("Gold/minutes").toInt();
    silver_reward = settings.value("Gold/silvers").toInt();

    ip_address = settings.value("Validation/ip_enable").toBool();
    ip_address_limit = settings.value("Validation/ip_limit").toInt();
    cultivation = settings.value("Validation/cultivation").toInt();
    level = settings.value("Validation/level").toInt();
    hours_game = settings.value("Validation/hours_game").toInt();

    gamedbd_host = settings.value("Gamedbd/host").toString();
    gamedbd_port = settings.value("Gamedbd/port").toInt();

    gdeliveryd_host = settings.value("Gdeliveryd/host").toString();
    gdeliveryd_port = settings.value("Gdeliveryd/port").toInt();

    mysql_host = settings.value("Mysql/host").toString();
    mysql_port = settings.value("Mysql/port").toInt();
    mysql_user = settings.value("Mysql/user").toString();
    mysql_pass = settings.value("Mysql/pass").toString();
    mysql_db   = settings.value("Mysql/db").toString();
}
