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
    }

    Text {
        text: "Record"
        anchors.top: descriptionTxt.bottom

        MouseArea {
            onClicked: { eventView.event.record(); }
            anchors.fill: parent
        }
    }
}
