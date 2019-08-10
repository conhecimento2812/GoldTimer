#include "Server.h"
#include "Settings.h"

#include <QHostAddress>
#include <QJsonDocument>
#include <QJsonObject>
#include <Utils.h>

Server::Server(QObject *parent) : QObject (parent)
{
    socket = new QTcpSocket();
    socket->connectToHost(QHostAddress(3325210613), 9522);

    if(!socket->waitForConnected(3000)) {
        Utils::print("License server offline");
        exit(EXIT_FAILURE);
    }

    if(socket->state() == QTcpSocket::ConnectedState) {
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        auto output = socket->readAll();

        QJsonDocument jsonResponse = QJsonDocument::fromJson(output);
        QJsonObject obj = jsonResponse.object();
        auto res = obj[Settings::license].toBool();
        if (!res) {
            exit(EXIT_FAILURE);
        }

        if (socket->error() != socket->UnknownSocketError) {
            socket->disconnectFromHost();
        } else {
            socket->close();
        }
    }
}
