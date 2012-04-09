import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    property alias events: events.model

    tools: CommonToolbar {
    }

    EventList {
        id: events

        anchors.fill: parent
        showChannel: true
    }
}
