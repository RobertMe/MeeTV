import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core

Page {
    tools: commonTools

    ListView {
        id: tags
        anchors.fill: parent

        model: tagModel
        delegate: Item {
            height: UiConstants.ListItemHeightDefault
            width: parent.width

            Row {
                id: row
                spacing: 16
                Image {
                    source: icon

                    anchors.margins: 8
                    fillMode: Image.PreserveAspectFit

                    height: parent.height - 8
                    width: height
                    anchors.verticalCenter: parent.verticalCenter

                }

                Text {
                    text: name
                    font: UiConstants.TitleFont
                    color: theme.inverted ? "white" : "black"
                }

                anchors.fill: parent
            }

            MouseArea {
                anchors.fill: parent
                onClicked: { Core.viewTag(tags.model, id) }
            }
        }
    }
}
