import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    property int leftMargin
    property int rightMargin
    property bool canNavigateNext: true

    width: parent.width - drilldown.width - 10

    anchors.topMargin: 8
    anchors.bottomMargin: anchors.topMargin

    signal clicked()

    BorderImage {
        id: background
        anchors.fill: parent
        // Fill page borders
        anchors.leftMargin: -parent.leftMargin
        anchors.rightMargin: -(parent.rightMargin + drilldown.width + 10)
        visible: mouseArea.pressed
        source: "image://theme/meegotouch-list" + (theme.inverted ? "-inverted" : "") + "-background-pressed-center"
    }

    Image {
        id: drilldown

        source: "image://theme/icon-m-common-drilldown-arrow" + (theme.inverted ? "-inverse" : "") + (!canNavigateNext ? "-disabled" : "")
        anchors.right: parent.right
        anchors.rightMargin: -width - 10
        anchors.verticalCenter: parent.verticalCenter
    }

    MouseArea {
        id: mouseArea
        anchors.fill: background
        onClicked: parent.clicked()
        enabled: canNavigateNext
    }
}
