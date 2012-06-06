import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    id: eventView

    property Event event

    tools: CommonToolbar {
        ToolIcon {
            id: recordIcon
            iconId: "toolbar-clock"
            onClicked: eventView.event.record()
            anchors.right: parent.menuIcon.left
        }
        menu: CommonMenu {
            MenuItem {
                text: qsTr("Next event")
                onClicked: Core.viewEvent(eventView.event.nextEvent)
                enabled: eventView.event.nextEvent !== null
            }
        }
    }

    Rectangle {
        id: header

        height: screen.currentOrientation === Screen.Portrait ? UiConstants.HeaderDefaultHeightPortrait : UiConstants.HeaderDefaultHeightLandscape
        width: parent.width
        anchors.top: parent.top
        color: "gray"

        Label {
            id: title
            text: event.title
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.margins: UiConstants.DefaultMargin
        }

        Grid {
            columns: screen.currentOrientation === Screen.Landscape ? 2 : 1

            anchors {
                right: parent.right
                verticalCenter: parent.verticalCenter
                margins: UiConstants.DefaultMargin
            }

            Label {
                id: start
                text: Qt.formatTime(event.start)
                font: UiConstants.FieldLabelFont
                width: 90
                horizontalAlignment: screen.currentOrientation === Screen.Landscape ? Text.AlignLeft : Text.AlignRight
            }

            Label {
                id: stop
                text: (screen.currentOrientation === Screen.Landscape ? "- " : "") + Qt.formatTime(event.stop)
                font: UiConstants.FieldLabelFont
                width: screen.currentOrientation === Screen.Landscape ? 100 : 90
                horizontalAlignment: screen.currentOrientation === Screen.Landscape ? Text.AlignLeft : Text.AlignRight
            }
        }
    }

    Flickable {
        anchors {
            top: header.bottom
            bottom: parent.bottom
            margins: UiConstants.DefaultMargin
        }

        width: parent.width
        contentHeight: contentItem.childrenRect.height
        clip: true

        Text {
            text: event.htmlDescription
            font: UiConstants.BodyTextFont
            width: parent.width
            wrapMode: Text.Wrap
            color: theme.inverted ? "white" : "black"
            onLinkActivated: Qt.openUrlExternally(link)
        }
    }
}
