import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import Htsp 1.0

Page {
    tools: commonTools

    SelectionDialog {
        id: channelDialog

        titleText: "Channel"

        model: channelModel
    }

    SelectionDialog {
        id: tagDialog

        titleText: "Tag"

        model: tagModel
    }

    Column {
        TextField {
            id: query

            width: parent.width

            platformSipAttributes: SipAttributes {
                actionKeyEnabled: true
                actionKeyHighlighted: true
                actionKeyLabel: "Search"
            }

            Keys.onReturnPressed: {
                Core.searchEvent(parent, query.text, channelDialog.selectedIndex, tagDialog.selectedIndex)
            }
        }

        Button {
            text: "Channel"
            onClicked: { channelDialog.open(); }
        }

        Button {
            text: "Tag"
            onClicked: { tagDialog.open(); }
        }

        Button {
            text: "Search"
            onClicked: { Core.searchEvent(parent, query.text, channelDialog.selectedIndex, tagDialog.selectedIndex) }
        }
    }
}
