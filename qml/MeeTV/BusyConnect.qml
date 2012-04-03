import QtQuick 1.1
import com.nokia.meego 1.0
import Htsp 1.0

Rectangle {
    id: busyConnect

    property alias text: busyTxt.text

    anchors.fill: parent
    opacity: 0.8
    color: "black"

    Column {
        anchors.centerIn: parent
        spacing: 10

        Label {
            id: busyTxt
            anchors.horizontalCenter: parent.horizontalCenter
            font: UiConstants.BodyTextFont
        }

        BusyIndicator {
            platformStyle: BusyIndicatorStyle { size: "large" }
            running: busyConnect.visible

            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    MouseArea {
        anchors.fill: parent
        enabled: parent.visible
        z: Number.MAX_VALUE
    }
}
