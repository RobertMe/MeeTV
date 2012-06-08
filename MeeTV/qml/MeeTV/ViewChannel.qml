import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    property Channel channel
    property alias events: eventsView.model
    property ModelHelper channelModel
    property int currentIndex

    tools: CommonToolbar {
        menu: CommonMenu {
            MenuItem {
                text: qsTr("Previous channel")
                onClicked: Core.viewChannel(channelModel.get(currentIndex - 1), channelModel, currentIndex - 1, true)
                enabled: currentIndex > 0
            }
            MenuItem {
                text: qsTr("Next channel")
                onClicked: Core.viewChannel(channelModel.get(currentIndex + 1), channelModel, currentIndex + 1, true)
                enabled: (currentIndex + 1) < channelModel.count
            }
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
        allowEventNavigation: true
    }
}
