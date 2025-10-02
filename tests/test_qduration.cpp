#include <QtTest/QtTest>
#include "qduration.h"

using namespace QtDuration;

class TestQDuration : public QObject
{
    Q_OBJECT
private slots:
    void testConstruction();
    void testFormatting();
    void testArithmetic();
    void testGetters();
    void testEdgeCases();
};

void TestQDuration::testConstruction()
{
    // Default constructor
    QDuration d0;
    QVERIFY(d0.isValid());
    QCOMPARE(d0.hours(), 0);
    QCOMPARE(d0.minutes(), 0);
    QCOMPARE(d0.seconds(), 0);

    // Constructor with QTime and days/months/years
    QTime t1(1, 2, 3); // 01:02:03
    QDuration d1(t1, 1, 2, 3); // 1 day, 2 months, 3 years
    QCOMPARE(d1.getTime(), t1);
    QCOMPARE(d1.days(), 1);
    QCOMPARE(d1.months(), 2);
    QCOMPARE(d1.years(), 3);
}

void TestQDuration::testFormatting()
{
    QDuration d(QTime(2, 30, 15), 0, 0, 0);
    QString s = d.toString();
    QVERIFY(!s.isEmpty()); // the exact string depends on your toString() implementation
}

void TestQDuration::testArithmetic()
{
    QDuration d(QTime(0, 0, 30)); // 30 seconds
    d.addSeconds(45);
    QCOMPARE(d.seconds(), 75 % 60);
    QCOMPARE(d.minutes(), 1); // should roll over to 1 minute

    d.addMinutes(59);
    QCOMPARE(d.hours(), 1); // should roll over after 60 minutes

    d.addDays(1);
    QCOMPARE(d.days(), 1);
}

void TestQDuration::testGetters()
{
    QDuration d(QTime(12, 34, 56), 10, 3, 2);
    QCOMPARE(d.hours(), 12);
    QCOMPARE(d.minutes(), 34);
    QCOMPARE(d.seconds(), 56);
    QCOMPARE(d.days(), 10);
    QCOMPARE(d.months(), 3);
    QCOMPARE(d.years(), 2);
    QVERIFY(d.isValid());
}

void TestQDuration::testEdgeCases()
{
    // Large duration
    QDuration d(QTime(23, 59, 59), 365, 12, 10);
    QVERIFY(d.toString().length() > 0);

    // Negative additions (if supported)
    QDuration neg;
    neg.addSeconds(-10);
    QCOMPARE(neg.seconds(), 0); // adjust this depending on your implementation
}

QTEST_MAIN(TestQDuration)
#include "test_qduration.moc"
