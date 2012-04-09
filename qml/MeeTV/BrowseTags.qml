import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core

Page {
    tools: CommonToolbar {
    }

    ListView {
        id: tags

        anchors.fill: parent
        anchors.margins: UiConstants.DefaultMargin
        anchors.topMargin: 8
        anchors.bottomMargin: anchors.topMargin

        model: tagModel
        delegate: ListMenuItem {
            height: UiConstants.ListItemHeightDefault

            leftMargin: tags.anchors.leftMargin
            rightMargin: tags.anchors.rightMargin

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

                Label {
                    text: name
                    font: UiConstants.TitleFont
                }

                anchors.fill: parent
                anchors.verticalCenter: parent.verticalCenter
            }

            onClicked: { Core.viewTag(tags.model, id) }
        }
    }

    ScrollDecorator {
        flickableItem: tags
    }
}
