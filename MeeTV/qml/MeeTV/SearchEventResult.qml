import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    property EventModel events

    onEventsChanged: eventsView.model = events.helper()

    tools: CommonToolbar {
    }

    EventList {
        id: eventsView

        anchors.fill: parent
        showChannel: true
    }
}
