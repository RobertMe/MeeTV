import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    tools: CommonToolbar {
    }

    property Channel channel
    property Tag tag

    onChannelChanged: channelName.text = channel.name
    onTagChanged: tagName.text = tag.name

    SelectionDialog {
        id: channelDialog

        titleText: qsTr("Channel")

        model: channelModel.helper()

        onAccepted: { channel = channelDialog.model.get(channelDialog.selectedIndex) }
    }

    SelectionDialog {
        id: tagDialog

        titleText: qsTr("Tag")

        model: tagModel.helper()

        onAccepted: { tag = tagDialog.model.get(tagDialog.selectedIndex) }
    }

    Column {
        width: parent.width
        spacing: 15

        Item {
            height: UiConstants.ListItemHeightDefault
            width: parent.width

            Column {
                anchors.fill: parent
                spacing: 5

                Label {
                    text: qsTr("Query")
                    font: UiConstants.TitleFont
                }

                TextField {
                    id: query

                    width: parent.width

                    platformSipAttributes: SipAttributes {
                        actionKeyEnabled: true
                        actionKeyHighlighted: true
                        actionKeyLabel: qsTr("Search")
                    }

                    Keys.onReturnPressed: {
                        Core.searchEvent(parent, query.text, channel, tag)
                    }
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: { query.forceActiveFocus()  }
            }
        }

        Item {
            height: UiConstants.ListItemHeightDefault
            width: parent.width

            Column {
                anchors.fill: parent
                spacing: 5

                Label {
                    text: qsTr("Channel")
                    font: UiConstants.TitleFont
                }

                Label {
                    id: channelName
                    font.pixelSize: 18
                }
            }

            Image {
                source: "image://theme/meegotouch-combobox-indicator" + (theme.inverted ? "-inverted" : "")
                anchors.right: parent.right;
                anchors.verticalCenter: parent.verticalCenter
            }

            MouseArea {
                anchors.fill: parent
                onClicked: { channelDialog.open(); }
            }
        }

        Item {
            height: UiConstants.ListItemHeightDefault
            width: parent.width

            Column {
                anchors.fill: parent
                spacing: 5

                Label {
                    text: qsTr("Tag")
                    font: UiConstants.TitleFont
                }

                Label {
                    id: tagName
                    font.pixelSize: 18
                }
            }

            Image {
                source: "image://theme/meegotouch-combobox-indicator" + (theme.inverted ? "-inverted" : "")
                anchors.right: parent.right;
                anchors.verticalCenter: parent.verticalCenter
            }

            MouseArea {
                anchors.fill: parent
                onClicked: { tagDialog.open(); }
            }
        }

        Button {
            text: qsTr("Search")
            onClicked: Core.searchEvent(parent, query.text, channel, tag)
            anchors.right: parent.right
        }
    }
}
