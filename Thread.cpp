#include "Thread.h"

void Thread::run()
{
    Worker worker;
    QTimer timer;

    connect(&timer, SIGNAL(timeout()), &worker, SLOT(onTimeout()));
    timer.setInterval(60 * 1000);
    timer.start();

    exec();
}
