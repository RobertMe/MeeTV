import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    tools: commonTools

    id: eventView

    property Event event

    Text {
        id: descriptionTxt
        text: event.description
        font: UiConstants.BodyTextFont
        width: parent.width
        wrapMode: Text.Wrap
        color: theme.inverted ? "white" : "black"
    }

    Text {
        text: "Record"
        anchors.top: descriptionTxt.bottom
        color: theme.inverted ? "white" : "black"

        MouseArea {
            onClicked: { eventView.event.record(); }
            anchors.fill: parent
        }
    }
}
