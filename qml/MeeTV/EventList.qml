import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

ListView {
    property bool showChannel: false

    id: events
    anchors.fill: parent
    anchors.margins: UiConstants.DefaultMargin

    delegate: ListMenuItem {

        height: titleTxt.height + startTxt.height

        leftMargin: events.anchors.leftMargin
        rightMargin: events.anchors.rightMargin

        Text {
            id: titleTxt
            text: title
            font: UiConstants.TitleFont
            width: parent.width
            clip: true
            color: theme.inverted ? "white" : "black"
        }

        Text {
            id: startTxt
            text: Qt.formatTime(start) + " - " + Qt.formatTime(stop)
            font: UiConstants.FieldLabelFont
            anchors.top: titleTxt.bottom
            color: theme.inverted ? "white" : "black"
        }

        Text {
            id: channelTxt
            text: channel
            font: UiConstants.FieldLabelFont
            anchors.top: startTxt.top
            anchors.right: parent.right
            visible: showChannel
            color: theme.inverted ? "white" : "black"
        }

        onClicked: { Core.viewEvent(events.model, id); }
    }
}
