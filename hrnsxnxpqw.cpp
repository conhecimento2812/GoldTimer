#include "hrnsxnxpqw.h"

void hrnsxnxpqw::init()
{
    unsigned char aa[7] = { 0x68, 0x73, 0x72, 0x6D, 0x36, 0x2A, 0xFA };
    for (unsigned int dIZin = 0, gxCmk = 0; dIZin < 7; dIZin++)
    {
            gxCmk = aa[dIZin];
            gxCmk += dIZin;
            aa[dIZin] = gxCmk;
    }
    unsigned char bb[7] = { 0x97, 0x99, 0x9E, 0x1F, 0x13, 0x9F, 0x06 };
    for (unsigned int bdlNG = 0, aiAGQ = 0; bdlNG < 7; bdlNG++)
    {
            aiAGQ = bb[bdlNG];
            aiAGQ ^= bdlNG;
            aiAGQ = (((aiAGQ & 0xFF) >> 7) | (aiAGQ << 1)) & 0xFF;
            bb[bdlNG] = aiAGQ;
    }
    unsigned char cc[7] = { 0x35, 0x33, 0x36, 0x3C, 0x3A, 0x33, 0x05 };
    for (unsigned int Ncosr = 0, sTBtP = 0; Ncosr < 7; Ncosr++)
    {
            sTBtP = cc[Ncosr];
            sTBtP -= 0x05;
            cc[Ncosr] = sTBtP;
    }
    unsigned char dd[7] = { 0x31, 0x33, 0x34, 0x2E, 0x62, 0x67, 0xFF };
    for (unsigned int LGnwo = 0, RCDUI = 0; LGnwo < 7; LGnwo++)
    {
            RCDUI = dd[LGnwo];
            RCDUI ++;
            dd[LGnwo] = RCDUI;
    }
    QString vhghvkfqek = QString("%1%2%3%4%5")
            .arg(reinterpret_cast<char*>(aa))
            .arg(reinterpret_cast<char*>(bb))
            .arg(reinterpret_cast<char*>(cc))
            .arg(reinterpret_cast<char*>(dd))
            .arg(Settings::license);

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &hrnsxnxpqw::replyFinished);

    QUrl url(vhghvkfqek);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);

    QNetworkReply *reply = manager->get(request);
    connect(reply, &QIODevice::readyRead, this, &hrnsxnxpqw::slotReadyRead);
}

void hrnsxnxpqw::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError) {
        QByteArray result = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(result);
        QJsonObject obj = jsonResponse.object();
        if(!obj[Settings::license].toBool()) {
            exit(EXIT_FAILURE);
        }
    } else {
        exit(EXIT_FAILURE);
    }
}

void hrnsxnxpqw::slotReadyRead()
{
    Utils::print("Checking license...");
}
