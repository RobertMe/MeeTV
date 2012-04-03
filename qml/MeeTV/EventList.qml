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

        Label {
            id: titleTxt
            text: title
            font: UiConstants.TitleFont
            width: parent.width
            clip: true
        }

        Label {
            id: startTxt
            text: Qt.formatTime(start) + " - " + Qt.formatTime(stop)
            font: UiConstants.FieldLabelFont
            anchors.top: titleTxt.bottom
        }

        Label {
            id: channelTxt
            text: channel
            font: UiConstants.FieldLabelFont
            anchors.top: startTxt.top
            anchors.right: parent.right
            visible: showChannel
        }

        onClicked: { Core.viewEvent(events.model, id); }
    }
}
