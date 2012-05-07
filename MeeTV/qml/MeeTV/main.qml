import QtQuick 1.1
import com.nokia.meego 1.0
import com.nokia.extras 1.1
import "core.js" as Core
import Htsp 1.0

PageStackWindow {
    id: appWindow

    initialPage: mainPage
    showStatusBar: false

    MainPage {
        id: mainPage
    }

    BusyConnect {
        id: busyConnect

        text: qsTr("Connecting")
    }

    About {
        id: about
    }

    InfoBanner {
        id: dvrEntryAdded

        property DvrEntry dvrEntry

        text: qsTr("Added recording %1").arg(dvrEntry.title)
        iconSource: "image://theme/icon-m-toolbar-clock-white"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.hide();
                Core.viewDvrEntry(parent.dvrEntry);
            }
        }
    }

    InfoBanner {
        id: errorMessage

        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.hide();
                settings.open();
            }
        }
    }

    InfoBanner {
        id: connectionLost
        timerEnabled: false
        text: qsTr("Connection lost")

        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.hide();
            }
        }
    }

    Connections {
        target: htsp
        onConnected: { busyConnect.text = qsTr("Syncing data") }
        onConnectError: { errorMessage.timerEnabled = false; errorMessage.text = qsTr("Unable to connect to server"); errorMessage.show(); }
        onConnectionLost: { connectionLost.show(); }
        onAccessDenied: { errorMessage.timerEnabled = false; errorMessage.text = qsTr("Access denied"); errorMessage.show(); }
        onDvrEntryAdded: { dvrEntryAdded.dvrEntry = dvrEntry; dvrEntryAdded.show(); }
        onSyncCompleted: { busyConnect.visible = false }
    }

    Component.onCompleted: { theme.inverted = true }

    Connections {
        target: platformWindow

        onActiveChanged: meetv.active = platformWindow.active
    }
}
