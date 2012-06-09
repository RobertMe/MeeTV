import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Item {
    id: root

    property bool showChannel: false
    property alias model: events.model

    anchors.margins: UiConstants.DefaultMargin

    ListView {
        id: events

        anchors.fill: parent
        clip: true

        section.property: "startDate"
        section.criteria: ViewSection.FullString
        section.delegate: Item {
            height: sectionTxt.height
            width: events.width

            Label {
                id: sectionTxt
                text: section
                font: UiConstants.GroupHeaderFont
                anchors.right: parent.right
            }

            Rectangle {
                height: 1
                color: "lightgrey"
                anchors.bottom: parent.bottom
                anchors.right: sectionTxt.left
                anchors.left: parent.left
                anchors.rightMargin: 20
            }
        }

        delegate: ListMenuItem {

            height: titleTxt.height + startTxt.height

            leftMargin: events.anchors.leftMargin
            rightMargin: events.anchors.rightMargin

            Label {
                id: titleTxt
                text: title
                font: UiConstants.TitleFont
                width: parent.width
                clip: true
            }

            Label {
                id: startTxt
                text: Qt.formatTime(start) + " - " + Qt.formatTime(stop)
                font: UiConstants.FieldLabelFont
                anchors.top: titleTxt.bottom
            }

            Label {
                id: channelTxt
                text: channel
                font: UiConstants.FieldLabelFont
                anchors.top: startTxt.top
                anchors.right: parent.right
                visible: root.showChannel
            }

            onClicked: { Core.viewEvent(events.model.get(index)); }
            mouseArea.onPressAndHold: {
                eventMenu.event = events.model.get(index);
                eventMenu.open();
            }
        }
    }

    ScrollDecorator {
        flickableItem: events
    }

    SectionScroller {
        listView: events
    }

    Menu {
        id: eventMenu

        property Event event

        MenuLayout {
            MenuItem {
                text: qsTr("Search on IMDd")
                onClicked: Core.searchOnImdb(eventMenu.event)
            }
        }
    }
}
