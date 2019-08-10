#include <QCoreApplication>

#include <Utils.h>
#include <Settings.h>
#include <Database.h>
#include <Thread.h>
#include <Worker.h>
#include <Server.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Utils::print("Gold Timer - Discord: @Conhecimento#2812 | v0.1.0");
    Utils::print(QString("Build date: %1 at %2").arg(__DATE__).arg(__TIME__));
    Utils::print(QString("Connecting Database"));
    Settings::Init(a.applicationDirPath());
    //hrnsxnxpqw hrnsxnxpqw;
    //hrnsxnxpqw.init();
    Server server;
    Database::Instance()->connect();

    Thread t;
    t.start();

    return a.exec();
}
