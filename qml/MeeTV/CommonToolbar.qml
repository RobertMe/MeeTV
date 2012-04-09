import QtQuick 1.1
import com.nokia.meego 1.0

ToolBarLayout {
    id: root

    property bool canGoBack: true
    property Menu menu: CommonMenu {
    }

    ToolIcon {
        id: toolbarBack
        platformIconId: "toolbar-back";
        onClicked:{ pageStack.pop() }
        visible: root.canGoBack
        anchors.left: parent.left
    }

    ToolIcon {
        platformIconId: "toolbar-view-menu"
        anchors.right: (parent === undefined) ? undefined : parent.right
        onClicked: (menu.status === DialogStatus.Closed) ? menu.open() : menu.close()
        visible: menu !== null
    }
}
