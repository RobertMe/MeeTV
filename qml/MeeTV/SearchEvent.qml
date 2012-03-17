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

    Column {
        TextField {
            id: query

            width: parent.width
        }

        Button {
            text: "Channel"
            onClicked: { channelDialog.open(); }
        }

        Button {
            text: "Search"
            onClicked: { Core.searchEvent(parent, query.text, channelDialog.selectedIndex) }
        }
    }
}
