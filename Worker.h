#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <iostream>
#include <Utils.h>
#include <Settings.h>
#include <Database.h>
#include <Network/Daemon.h>

class Worker : public QObject
{
    Q_OBJECT
public:
    bool ipManager(QString ip);
    void ipsCleaner();

protected slots:
    void onTimeout();

private:
    Daemon *daemon;
    Settings settings;
    QHash<QString, uint> ips;
};

#endif // WORKER_H
