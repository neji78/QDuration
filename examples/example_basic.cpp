#include <QCoreApplication>
#include <QDebug>
#include <QDuration>

using namespace QtDuration;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Construct from QTime + days + months + years
    QTime t1(1, 1, 1);   // 01:01:01
    QDuration d1(t1, 0, 0, 0);   // 1h 1m 1s

    QTime t2(0, 45, 0);  // 45 minutes
    QDuration d2(t2, 0, 0, 0);

    QTime t3(0, 0, 0);   // midnight, but add days/months/years
    QDuration d3(t3, 1, 2, 0);   // 1 day, 2 months, 0 years

    qDebug() << "d1:" << d1;
    qDebug() << "d2:" << d2;
    qDebug() << "d3:" << d3;

    return 0;
}
