import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core

Page {
    id: root

    tools: CommonToolbar {
    }

    ListView {
        id: tags

        anchors.fill: parent
        anchors.margins: UiConstants.DefaultMargin
        anchors.topMargin: 8
        anchors.bottomMargin: anchors.topMargin

        model: tagModel.helper(root)
        visible: model.count > 0
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

            onClicked: { Core.viewTag(tags.model.get(index)) }
        }
    }

    ScrollDecorator {
        flickableItem: tags
    }

    Column {
        width: parent.width
        visible: tags.model.count === 0
        spacing: 10

        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            text: qsTr("No tags defined in TVheadend")
            anchors.horizontalCenter: parent.horizontalCenter
            font: UiConstants.SmallTitleFont
        }

        Label {
            width: parent.width
            text: qsTr("Define some tags in TVHeadend first")
            wrapMode: Text.Wrap
            font: UiConstants.BodyTextFont
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
