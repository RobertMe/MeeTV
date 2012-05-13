import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    property Channel channel
    property alias events: eventsView.model

    tools: CommonToolbar {
        ToolIcon {
            id: playIcon
            iconId: "toolbar-mediacontrol-play"
            onClicked: Core.playChannel(channel);
            anchors.right: parent.menuIcon.left
        }
    }

    Rectangle {
        id: header

        height: screen.currentOrientation === Screen.Portrait ? UiConstants.HeaderDefaultHeightPortrait : UiConstants.HeaderDefaultHeightLandscape
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
        id: eventsView

        anchors {
            top: header.bottom
            bottom: parent.bottom
            margins: UiConstants.DefaultMargin
        }
        width: parent.width
    }
}
