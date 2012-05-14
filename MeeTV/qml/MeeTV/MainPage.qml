import QtQuick 1.1
import com.nokia.meego 1.0
import "core.js" as Core
import "player.js" as Player
import Htsp 1.0

Page {
    id: mainPage
    QtObject {
        id: appProperties
        property Item currentPlayer
    }

    tools: CommonToolbar {
        canGoBack: false
    }

    ListModel {
        id: mainOptions

        ListElement {
            name: QT_TR_NOOP("Browse tags")
            page: "BrowseTags.qml"
        }

        ListElement {
            name: QT_TR_NOOP("View recordings")
            page: "ViewRecordings.qml"
        }

        ListElement {
            name: QT_TR_NOOP("Search event")
            page: "SearchEvent.qml"
        }

        ListElement {
            name: QT_TR_NOOP("Show player")
            run: 'Player.reopenPlayer();'
            hide: true
        }
    }

    ListView {
        id: mainMenu
        anchors.fill: parent
        model: mainOptions
        anchors.leftMargin: 10
        anchors.rightMargin: 10

        delegate: ListMenuItem {
            leftMargin: mainMenu.anchors.leftMargin
            rightMargin: mainMenu.anchors.rightMargin

            height: UiConstants.ListItemHeightDefault

            Label {
                text: qsTr(name)
                font: UiConstants.TitleFont
                anchors.verticalCenter: parent.verticalCenter
            }

            onClicked:
            {
                if(run)
                    eval(run);
                if(page)
                    Core.gotoPage(page)
            }

            visible: !hide
        }
    }

    ScrollDecorator {
        flickableItem: mainMenu
    }
}
