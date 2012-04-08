import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    tools: commonTools

    property Channel channel
    property alias events: events.model

    Rectangle {
        id: header

        height: 100
        width: parent.width
        anchors.top: parent.top
        color: "gray"

        Image {
            id: channelIcon
            height: parent.height - 20
            width: height
            source: channel.iconUrl
            anchors.left: parent.left;
            anchors.leftMargin: 16
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            id: channelName
            text: channel.name
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: channelIcon.right
            anchors.margins: UiConstants.DefaultMargin
        }
    }

    EventList {
        id: events

        anchors {
            top: header.bottom
            bottom: parent.bottom
            margins: UiConstants.DefaultMargin
        }
        width: parent.width
    }
}
