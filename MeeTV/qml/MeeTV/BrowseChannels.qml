import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import "player.js" as Player
import Htsp 1.0

Page {
    id: root

    tools: CommonToolbar {
    }

    anchors.fill: parent

    property alias channels: channelsView.model
    property Tag tag

    onTagChanged: {
        channels = tag.channelsModel.helper(root)
        header.text = tag.name
    }

    SelectionDialog {
        id: tagSelection

        titleText: qsTr("Select tag")
        model: tagModel.helper(root)
        onAccepted: {
            root.tag = tagSelection.model.get(tagSelection.selectedIndex)
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
        id: channelsView

        anchors {
            top: header.bottom
            bottom: parent.bottom
            margins: UiConstants.DefaultMargin
        }
        width: parent.width
        clip: true

        delegate: ListMenuItem {
            height: UiConstants.ListItemHeightDefault

            leftMargin: channelsView.anchors.leftMargin
            rightMargin: channelsView.anchors.rightMargin

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

            canNavigateNext: event !== ""
            onClicked:  { Core.viewChannel(channelsView.model.get(index)) }
            mouseArea.onPressAndHold: { channelMenu.channel = channelsView.model.get(index); channelMenu.open(); }
        }
    }

    ScrollDecorator {
        flickableItem: channelsView
    }

    Menu {
        id: channelMenu

        property Channel channel

        visualParent: pageStack
        MenuLayout {
            MenuItem {
                text: qsTr("Play")
                onClicked: channelMenu.channel && Player.playChannel(channelMenu.channel)
            }
        }
    }
}
