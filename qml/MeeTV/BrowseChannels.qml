import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core

Page {
    tools: commonTools

    property alias channels: channels.model

    ListView {
        id: channels

        anchors.fill: parent
        anchors.margins: UiConstants.DefaultMargin

        clip: true

        model: channelModel
        delegate: ListMenuItem {
            height: UiConstants.ListItemHeightDefault

            leftMargin: channels.anchors.leftMargin
            rightMargin: channels.anchors.rightMargin

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
}
