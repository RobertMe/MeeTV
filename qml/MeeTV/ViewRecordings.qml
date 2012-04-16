import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    tools: CommonToolbar {
    }

    ListView {
        id: recordings
        anchors.fill: parent
        anchors.margins: UiConstants.DefaultMargin

        clip: true

        section.property: "state"
        section.criteria: ViewSection.FullString
        section.delegate: Item {
            height: sectionTxt.height
            width: recordings.width

            Label {
                id: sectionTxt
                text: section == DvrEntry.Completed ? qsTr("Completed") : (section == DvrEntry.Invalid ? qsTr("Invalid") : (section == DvrEntry.Missed ? qsTr("Missed") : (section == DvrEntry.Recording ? qsTr("Recording") : qsTr("Scheduled"))))
                font: UiConstants.GroupHeaderFont
                anchors.right: parent.right
            }

            Rectangle {
                height: 1
                color: "lightgrey"
                anchors.bottom: parent.bottom
                anchors.right: sectionTxt.left
                anchors.left: parent.left
                anchors.rightMargin: 20
            }
        }

        model: dvrEntriesModel.helper()
        onModelChanged: model.sort(2)
        delegate: ListMenuItem {
            height: UiConstants.ListItemHeightDefault

            leftMargin: recordings.anchors.leftMargin
            rightMargin: recordings.anchors.rightMargin

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
            }

            onClicked: { Core.viewDvrEntry(recordings.model.get(index)) }
        }
    }

    ScrollDecorator {
        flickableItem: recordings
    }
}
