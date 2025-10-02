# QtDuration
QtDuration is a lightweight Qt-based library that provides a `QDuration` class for handling and formatting time durations in a Qt-friendly way.
It supports both C++ and QML usage.

# ✨ Features
- Simple QDuration class for representing durations
- Conversion between seconds, minutes, hours, days
- Formatting to human-readable strings ("1h 20m 5s", "02:15:00", etc.)
- QML plugin (import QtDuration 1.0)
- Qt-style headers (#include <QtDuration/QDuration>)

# 📦 Installation
### Build & Install
```
git clone https://github.com/neji78/QDuration.git
cd QDuration
cmake -B build -S . -DCMAKE_PREFIX_PATH="C:/Qt/6.8.1/msvc2019_64" -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
cmake --install build --prefix install
```
This will install:
```
install/
 ├── include/QtDuration/
 │   ├── qduration.h
 │   └── QDuration
 ├── bin/QtDuration.dll
 └── qml/QtDuration/ (if QML plugin enabled)
```
# 🔧 Usage in C++
```
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

```
and outputs:
```
d1: QDuration(0 Years,0 Months,0 Days,"01:01:01:000" 3661s)
d2: QDuration(0 Years,0 Months,0 Days,"00:45:00:000" 2700s)
d3: QDuration(0 Years,2 Months,1 Days,"00:00:00:000" 5270400s)
```

# 🎨 Usage in QML
```
import QtQuick 2.15
import QtDuration 1.0

Rectangle {
    width: 300
    height: 100

    Duration {
        id: dur
        seconds: 3661
    }

    Text {
        anchors.centerIn: parent
        text: dur.toString()   // "1h 1m 1s"
    }
}
```
# 📂 Project Structure
```
QDuration/
 ├── src/
 │   ├── qduration.h
 │   ├── qduration.cpp
 │   ├── QDuration
 │   └── plugin.cpp   (QML registration)
 ├── CMakeLists.txt
 └── examples/
     └── main.qml
```
# 🛠 Requirements
- Qt 6.2+ (tested with Qt 6.8.1, MSVC/MinGW, Linux, macOS)
- CMake 3.14+
