#ifndef HRNSXNXPQW_H
#define HRNSXNXPQW_H

#include <QNetworkAccessManager>
#include <QObject>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <Settings.h>
#include <Utils.h>

class hrnsxnxpqw : public QObject
{
    Q_OBJECT
public:
    explicit hrnsxnxpqw(QObject *parent = nullptr)  : QObject(parent) {}
    void init();
    ~hrnsxnxpqw(){
        manager->disconnect();
    }
public slots:
    void replyFinished(QNetworkReply *reply);
    void slotReadyRead();

public:
    QNetworkAccessManager *manager;
};

#endif // HRNSXNXPQW_H
