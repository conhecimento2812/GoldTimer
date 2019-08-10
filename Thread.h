#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QTimer>
#include <Worker.h>

class Thread : public QThread
{
    Q_OBJECT
protected:
    void run();

    Settings settings;
};

#endif // THREAD_H
