#include "Database.h"

Database* Database::self = nullptr;

void Database::connect()
{
    db = QSqlDatabase::addDatabase("QMYSQL", "mysql");
    db.setHostName(Settings::mysql_host);
    db.setPort(Settings::mysql_port);
    db.setUserName(Settings::mysql_user);
    db.setPassword(Settings::mysql_pass);
    db.setDatabaseName(Settings::mysql_db);
    db.setConnectOptions("MYSQL_OPT_RECONNECT=1;MYSQL_OPT_CONNECT_TIMEOUT=300");
    if (!db.open()) {
        Utils::print(QString("Error occurred opening the mysql"));
        Utils::print(db.lastError().text());
        exit(0);
    }

    sqlite = QSqlDatabase::addDatabase("QSQLITE", "sqlite");
    sqlite.setDatabaseName(Settings::path + "/goldtimer.db");
    if (!sqlite.open()) {
        Utils::print(QString("Error occurred opening the goldtimer.db"));
        Utils::print(sqlite.lastError().text());
        exit(0);
    } else {
        sqliteCreateTable();
    }

    Utils::print("Successfully connected to database");
}

void Database::sqliteCreateTable()
{
    QSqlQuery sqliteCreateTable(sqlite);
    sqliteCreateTable.prepare("CREATE TABLE IF NOT EXISTS goldtimer ( id INTEGER PRIMARY KEY AUTOINCREMENT, userid INTEGER, minutes INTEGER DEFAULT 0 )");
    if (!sqliteCreateTable.exec()) {
        Utils::print("Error occurred creating table.");
        Utils::print(sqlite.lastError().text());
        exit(0);
    }
}

void Database::minuteAdd(const int &userid, const int &minute)
{
    int minutesForAdd = minuteShow(userid) + minute;

    QSqlQuery sql(sqlite);
    sql.prepare("insert or replace into goldtimer (id, userid, minutes) values ((select id from goldtimer where userid = ?), ?, ?);");
    sql.addBindValue(userid);
    sql.addBindValue(userid);
    sql.addBindValue(minutesForAdd);
    if (!sql.exec()) {
        Utils::print("Error occurred updating minutes.");
        Utils::print(sqlite.lastError().text());
    }
}

void Database::minuteTruncate(const int &userid)
{
    QSqlQuery sql(sqlite);
    sql.prepare("update goldtimer set minutes = 0 where userid = ?");
    sql.addBindValue(userid);
    if (!sql.exec()) {
        Utils::print("Error occurred truncate minutes.");
        Utils::print(sqlite.lastError().text());
    }
}

int Database::minuteShow(const int &userid)
{
    QSqlQuery sql(sqlite);
    sql.prepare("select minutes from goldtimer where userid = ?");
    sql.addBindValue(userid);
    if (!sql.exec()) {
        Utils::print("Error occurred get minutes.");
        Utils::print(sqlite.lastError().text());
    }
    sql.next();
    return sql.value(0).toInt();
}

int Database::useCash(const int &userid, const int &zoneid, const int &sn, const int &aid, const int &point, const int &cash, const int &status)
{
    QSqlQuery sql(db);
    sql.prepare("CALL usecash(?, ?, ?, ?, ?, ?, ?, @out1)");
    sql.addBindValue(userid);
    sql.addBindValue(zoneid);
    sql.addBindValue(sn);
    sql.addBindValue(aid);
    sql.addBindValue(point);
    sql.addBindValue(cash);
    sql.addBindValue(status);
    sql.exec();
    sql.exec("SELECT @out1");
    sql.next();

    return sql.value(0).toInt();
}
