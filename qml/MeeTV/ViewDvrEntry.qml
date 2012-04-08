import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    tools: commonTools

    id: dvrEntryView

    property DvrEntry dvrEntry

    Rectangle {
        id: header

        height: screen.currentOrientation === Screen.Portrait ? UiConstants.HeaderDefaultHeightPortrait : UiConstants.HeaderDefaultHeightLandscape
        width: parent.width
        anchors.top: parent.top
        color: "gray"

        Label {
            id: title
            text: dvrEntry.title
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.margins: UiConstants.DefaultMargin
        }

        Column {
            id: times

            anchors {
                right: parent.right
                verticalCenter: parent.verticalCenter
                margins: UiConstants.DefaultMargin
            }
            width: 100

            Label {
                text: Qt.formatTime(dvrEntry.start)
                font: UiConstants.FieldLabelFont
                width: parent.width
                horizontalAlignment: Text.AlignRight
            }

            Label {
                text: Qt.formatTime(dvrEntry.stop)
                font: UiConstants.FieldLabelFont
                width: parent.width
                horizontalAlignment: Text.AlignRight
            }
        }

        Label {
            text: dvrEntry.state == DvrEntry.Completed ? "Completed" : (dvrEntry.state == DvrEntry.Invalid ? "Invalid" : (dvrEntry.state == DvrEntry.Missed ? "Missed" : (dvrEntry.state == DvrEntry.Recording ? "Recording" : "Scheduled")))
            font: UiConstants.FieldLabelFont
            horizontalAlignment: Text.AlignRight
            anchors {
                top: times.top
                right: times.left
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
            id: descriptionTxt
            text: dvrEntry.description
            font: UiConstants.BodyTextFont
            width: parent.width
            wrapMode: Text.Wrap
            color: theme.inverted ? "white" : "black"
        }

        ButtonRow {
            anchors.top: descriptionTxt.bottom
            Button {
                id: cancelButton
                visible: dvrEntry.state == DvrEntry.Recording
                text: "Cancel"
                onClicked: { dvrEntry.cancel() }
            }

            Button {
                id: deleteButton
                text: "Delete"
                onClicked: { dvrEntry.remove(); pageStack.pop() }
            }
        }
    }
}
