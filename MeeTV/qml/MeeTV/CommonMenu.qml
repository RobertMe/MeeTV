import QtQuick 1.1
import com.nokia.meego 1.0

Menu {
    default property alias menuItems: layout.menuChildren

    visualParent: pageStack

    CustomMenuLayout {
        id: layout
    }

    Component.onCompleted: {
        Qt.createQmlObject("import com.nokia.meego 1.0; MenuItem { text: '" + qsTr("About MeeTV") + "'; onClicked: about.open(); }", layout.menuColumn);
    }
}
