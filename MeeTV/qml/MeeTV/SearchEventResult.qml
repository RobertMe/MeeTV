import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    id: root

    property EventModel events

    onEventsChanged: eventsView.model = events.helper(root)

    tools: CommonToolbar {
    }

    EventList {
        id: eventsView

        anchors.fill: parent
        showChannel: true

        visible: model.count > 0
    }

    Label {
        text: qsTr("No events found for the given search")

        visible: eventsView.model.count === 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
