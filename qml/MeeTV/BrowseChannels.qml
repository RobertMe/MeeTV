import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core

Page {
    tools: commonTools

    property alias channels: channels.model

    ListView {
        id: channels
        anchors.fill: parent
        clip: true

        model: channelModel
        delegate: Item {
            height: UiConstants.ListItemHeightDefault
            width: parent.width

            Row {
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
                    Text {
                        text: name
                        font: UiConstants.TitleFont
                    }

                    Text {
                        text: event
                        font: UiConstants.BodyTextFont
                    }
                }

                anchors.fill: parent
            }

            MouseArea {
                anchors.fill: row
                onClicked: { Core.viewChannel(channelModel, id) }
            }
        }
    }
}
