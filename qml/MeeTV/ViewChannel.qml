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

        header: Column {
            width: events.width
            Image {
                id: logo
                source: channel.iconUrl
            }

            Text {
                id: name
                text: channel.name
                color: theme.inverted ? "white" : "black"
            }

            Rectangle {
                height: 1
                width: parent.width
                color: "gray"
            }
        }
    }
}
