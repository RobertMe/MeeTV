import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    id: eventView

    property Event event

    tools: CommonToolbar {
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

        Column {
            anchors {
                right: parent.right
                verticalCenter: parent.verticalCenter
                margins: UiConstants.DefaultMargin
            }
            width: 100

            Label {
                id: start
                text: Qt.formatTime(event.start)
                font: UiConstants.FieldLabelFont
                width: parent.width
                horizontalAlignment: Text.AlignRight
            }

            Label {
                id: stop
                text: Qt.formatTime(event.stop)
                font: UiConstants.FieldLabelFont
                width: parent.width
                horizontalAlignment: Text.AlignRight
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

        Column {
            width: parent.width
            spacing: 10

            Text {
                text: event.description
                font: UiConstants.BodyTextFont
                width: parent.width
                wrapMode: Text.Wrap
                color: theme.inverted ? "white" : "black"
            }

            Text {
                text: event.longDescription
                font: UiConstants.BodyTextFont
                width: parent.width
                wrapMode: Text.Wrap
                color: theme.inverted ? "white" : "black"
            }

            Button {
                text: qsTr("Record")
                onClicked: { eventView.event.record(); }
            }
        }
    }
}
