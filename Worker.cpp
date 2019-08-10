#include "Worker.h"

void Worker::onTimeout()
{
    Database *db = Database::Instance();

    QVector<GMPlayerInfo> users = Daemon::GDeliveryd()->getUsersOnline();
    Utils::print(QString("Users online: %1").arg(users.size()));

    ipsCleaner();
    for(int i = 0; i < users.size(); i++) {
        GMPlayerInfo user = users.value(i);
        GRoleStatus body = Daemon::Gamedbd()->GetRoleStatus(user.roleid);

        // ip
        if (settings.ip_address) {
            QVector<PlayerConsumeInfo> consumeinfo = Daemon::Gamedbd()->DBGetConsumeInfos(user.roleid);
            QString ip = Utils::getIp(consumeinfo[0].login_ip);
            if (ipManager(ip))
                continue;
        }

        if (body.level < settings.level)
            continue;

        if (body.level2 < settings.cultivation)
            continue;

        db->minuteAdd(user.userid);
        int minutes = db->minuteShow(user.userid);
        if (minutes >= settings.minutes) {
            db->minuteTruncate(user.userid);
            db->useCash(user.userid, 1, 0, 1, 0, settings.silver_reward, 1);
            Utils::print(QString("userid: %1 minutes: %2 silver reward: %3").arg(user.userid).arg(minutes).arg(settings.silver_reward));
        }
    }
}

bool Worker::ipManager(QString ip)
{
    if (!settings.ip_address)
        return false;

    if (ips.contains(ip)) {
        ++ips[ip];
    } else {
        ips.insert(ip, 1);
    }

    if (ips[ip] > static_cast<uint>(settings.ip_address_limit)) {
        return true;
    }

    return false;
}

void Worker::ipsCleaner()
{
    ips.clear();
}
