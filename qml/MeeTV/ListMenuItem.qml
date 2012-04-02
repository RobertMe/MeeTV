import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    property int leftMargin
    property int rightMargin

    width: parent.width

    anchors.topMargin: 8
    anchors.bottomMargin: anchors.topMargin

    signal clicked()

    BorderImage {
        id: background
        anchors.fill: parent
        // Fill page borders
        anchors.leftMargin: -parent.leftMargin
        anchors.rightMargin: -parent.rightMargin
        visible: mouseArea.pressed
        source: "image://theme/meegotouch-list" + (theme.inverted ? "-inverted" : "") + "-background-pressed-center"
    }

    Image {
        source: "image://theme/icon-m-common-drilldown-arrow" + (theme.inverted ? "-inverse" : "")
        anchors.right: parent.right;
        anchors.verticalCenter: parent.verticalCenter
    }

    MouseArea {
        id: mouseArea
        anchors.fill: background
        onClicked: parent.clicked()
    }
}
