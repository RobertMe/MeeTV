import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    tools: commonTools

    property Channel channel
    property alias events: events.model

    EventList {
        id: events

        header: Item {
            width: events.width
            height: channelInfo.height + 10

            Row {
                id: channelInfo

                spacing: 10

                Image {
                    id: logo
                    source: channel.iconUrl
                    width: 100
                    height: width
                }

                Label {
                    id: name
                    text: channel.name
                    font: UiConstants.HeaderFont
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                height: 1
                width: parent.width
                color: "lightgray"
                anchors.bottom: parent.bottom
            }
        }
    }
}
