import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    tools: commonTools

    id: dvrEntryView

    property DvrEntry dvrEntry

    Text {
        id: descriptionTxt
        text: dvrEntry.description
        font: UiConstants.BodyTextFont
        width: parent.width
        wrapMode: Text.Wrap
    }

    Row {
        anchors.top: descriptionTxt.bottom
        Button {
            id: cancelButton
            visible: dvrEntry.state == 2
            text: "Cancel"
            onClicked: { dvrEntry.cancel() }
        }

        Button {
            id: deleteButton
            text: "Delete"
            onClicked: { dvrEntry.remove(); pageStack.pop() }
        }
    }
}
