import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    tools: commonTools

    ListModel {
        id: mainOptions

        ListElement {
            name: "Browse tags"
            page: "BrowseTags.qml"
        }

        ListElement {
            name: "Browse channels"
            page: "BrowseChannels.qml"
        }

        ListElement {
            name: "View recordings"
            page: "ViewRecordings.qml"
        }

        ListElement {
            name: "Search event"
            page: "SearchEvent.qml"
        }
    }

    ListView {
        id: mainMenu
        anchors.fill: parent
        model: mainOptions

        delegate: Item {
            id: menuItem
            height: UiConstants.ListItemHeightDefault
            width: parent.width

            Text {
                text: name
                font: UiConstants.TitleFont
                color: theme.inverted ? "white" : "black"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: { Core.gotoPage(page); }
            }
        }
    }
}
