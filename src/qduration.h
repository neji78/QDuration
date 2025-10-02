#ifndef QDURATION_H
#define QDURATION_H

#include "qduration_global.h"
#include <QTime>
#include <QObject>
#include <QString>
#include <QDebug>

namespace QtDuration {
class QDuration;
QDURATION_EXPORT QDebug operator<<(QDebug dbg, const QDuration &duration);
class QDURATION_EXPORT QDuration : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int hours READ hours CONSTANT)
    Q_PROPERTY(int minutes READ minutes CONSTANT)
    Q_PROPERTY(int seconds READ seconds CONSTANT)
    Q_PROPERTY(int milliseconds READ milliseconds CONSTANT)
    Q_PROPERTY(int days READ days CONSTANT)
    Q_PROPERTY(int months READ months CONSTANT)
    Q_PROPERTY(int years READ years CONSTANT)
    Q_PROPERTY(bool valid READ isValid CONSTANT)

public:
    explicit QDuration(QObject *parent = nullptr);
    explicit QDuration(QTime time, int days = 0, int months = 0, int years = 0, QObject *parent = nullptr);

    // String conversions
    Q_INVOKABLE QString toString() const;
    // Q_INVOKABLE static QDuration fromString(const QString &timeDurationString, const QString &dateDurationString);
    // Q_INVOKABLE static QDuration fromString(const QString &durationString);

    // Add time units
    Q_INVOKABLE void addMilliseconds(int milliseconds);
    Q_INVOKABLE void addSeconds(int seconds);
    Q_INVOKABLE void addMinutes(int minutes);
    Q_INVOKABLE void addHours(int hours);
    Q_INVOKABLE void addDays(int days);
    Q_INVOKABLE void addMonths(int months);
    Q_INVOKABLE void addYears(int years);

    // Reset / copy
    Q_INVOKABLE void clearDuration();
    // Q_INVOKABLE QDuration toDuration() const;

    // Getters
    Q_INVOKABLE int seconds() const;
    Q_INVOKABLE int milliseconds() const;
    Q_INVOKABLE int timeSeconds() const;
    Q_INVOKABLE int timeMilliseconds() const;
    Q_INVOKABLE QTime getTime() const;
    Q_INVOKABLE bool isValid() const;

    int hours() const;
    int minutes() const;
    int days() const { return days_; }
    int months() const { return months_; }
    int years() const { return years_; }

    int timeSeconds(QTime time) const;
    int timeMilliseconds(QTime time) const;
private:
    int days_;
    int months_;
    int years_;
    QTime time_;
};

} // namespace QtDuration

#endif // QDURATION_H
