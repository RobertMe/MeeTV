import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core

Page {
    tools: commonTools
    anchors.fill: parent

    property alias channels: channels.model

    SelectionDialog {
        id: tagSelection

        titleText: qsTr("Select tag")
        model: tagModel
        onAccepted: {
            var tag = tagSelection.model.getTagByIndex(tagSelection.selectedIndex);
            channels.model = tag.channelsModel
            header.text = tag.name
        }
    }

    Rectangle {
        id: header

        property alias text: selectedTag.text

        height: screen.currentOrientation === Screen.Portrait ? UiConstants.HeaderDefaultHeightPortrait : UiConstants.HeaderDefaultHeightLandscape
        width: parent.width
        anchors.top: parent.top
        color: "gray"

        Label {
            id: selectedTag
            text: qsTr("All")
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.margins: UiConstants.DefaultMargin
        }

        Image {
            source: "image://theme/meegotouch-combobox-indicator" + (theme.inverted ? "-inverted" : "")
            anchors.right: parent.right;
            anchors.verticalCenter: parent.verticalCenter
        }

        MouseArea {
            anchors.fill: parent

            onClicked: tagSelection.open();
        }
    }

    ListView {
        id: channels

        anchors {
            top: header.bottom
            bottom: parent.bottom
            margins: UiConstants.DefaultMargin
        }
        width: parent.width
        clip: true

        model: channelModel
        delegate: ListMenuItem {
            height: UiConstants.ListItemHeightDefault

            leftMargin: channels.anchors.leftMargin
            rightMargin: channels.anchors.rightMargin

            Row {
                clip: true
                id: row
                spacing: 16
                Image {
                    source: icon

                    anchors.margins: 8
                    fillMode: Image.PreserveAspectFit

                    height: parent.height - 8
                    width: height
                    anchors.verticalCenter: parent.verticalCenter

                }

                Column {
                    Label {
                        text: name
                        font: UiConstants.TitleFont
                    }

                    Label {
                        text: event
                        font: UiConstants.BodyTextFont
                    }
                }

                anchors.fill: parent
                anchors.verticalCenter: parent.verticalCenter
            }

            onClicked:  { Core.viewChannel(channelModel, id) }
        }
    }

    ScrollDecorator {
        flickableItem: channels
    }
}
