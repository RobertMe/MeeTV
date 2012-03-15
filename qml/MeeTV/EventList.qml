import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

ListView {
    id: events
    anchors.fill: parent

    delegate: Column {
        Item {
            width: events.width
            height: titleTxt.height + startTxt.height

            Text {
                id: titleTxt
                text: title
                font: UiConstants.TitleFont
                clip: true
            }

            Text {
                id: startTxt
                text: Qt.formatTime(start) + " - " + Qt.formatTime(stop)
                font: UiConstants.FieldLabelFont
                anchors.top: titleTxt.bottom
            }

            MouseArea {
                onClicked: { Core.viewEvent(events.model, id); }
                anchors.fill: parent
            }
        }
    }
}
