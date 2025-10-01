import QtQuick 2.15
import QtDuration 1.0

Rectangle {
    width: 300; height: 100

    Duration {
        id: dur
        seconds: 3661
    }

    Text {
        anchors.centerIn: parent
        text: dur.toString()   // e.g. "1h 1m 1s"
    }
}
