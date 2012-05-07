import QtQuick 1.1
import com.nokia.meego 1.0

Menu {
    visualParent: pageStack
    MenuLayout {
        MenuItem {
            text: qsTr("About MeeTV")
            onClicked: about.open();
        }
    }
}
