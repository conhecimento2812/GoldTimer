#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>
#include <iostream>

#include <Settings.h>
#include <Utils.h>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr)  : QObject(parent) {}
    ~Database() { db.close(); sqlite.close(); }
    void connect();

    void sqliteCreateTable();
    void minuteAdd(const int &userid, const int &minute = 1);
    void minuteTruncate(const int &userid);
    int minuteShow(const int &userid);

    int useCash(const int &userid, const int &zoneid, const int &sn, const int &aid, const int &point, const int &cash, const int &status);
    static Database *Instance()
    {
        if (!self)
            self = new Database();
        return self;
    }
    static Database *self;

private:
    QSqlDatabase db;
    QSqlDatabase sqlite;
};

#endif // DATABASE_H
