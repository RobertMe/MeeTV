import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.1

PageStackWindow {
    id: appWindow

    initialPage: mainPage
    showStatusBar: false

    MainPage {
        id: mainPage
    }

    ToolBarLayout {
        id: commonTools
        visible: true

        ToolIcon {
            id: toolbarBack
            platformIconId: "toolbar-back";
            onClicked:{ pageStack.pop() }
        }

        ToolIcon {
            platformIconId: "toolbar-view-menu"
            anchors.right: (parent === undefined) ? undefined : parent.right
            onClicked: (myMenu.status === DialogStatus.Closed) ? myMenu.open() : myMenu.close()
        }
    }

    Menu {
        id: myMenu
        visualParent: pageStack
        MenuLayout {
            MenuItem { text: qsTr("Sample menu item") }
        }
    }

    BusyConnect {
        id: busyConnect

        text: "Connecting"
    }

    InfoBanner {
        id: dvrEntryAdded
        iconSource: "image://theme/icon-m-toolbar-clock-white"
    }

    InfoBanner {
        id: errorMessage
    }

    Connections {
        target: htsp
        onConnected: { busyConnect.text = "Syncing data" }
        onAccessDenied: { errorMessage.timerEnabled = false; errorMessage.text = "Access denied"; errorMessage.show(); }
        onDvrEntryAdded: { dvrEntryAdded.text = "Added recording " + dvrEntry.title; dvrEntryAdded.show(); }
        onSyncCompleted: { busyConnect.visible = false }
    }

    Component.onCompleted: { theme.inverted = true }
}
