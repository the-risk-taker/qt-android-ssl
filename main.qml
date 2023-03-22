import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: window

    width: 640
    height: 480
    visible: true
    title: qsTr("SSL Android support")

    Text {
        text: window.title + '\n' + message
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
    }
}
