import QtQuick 1.1
import com.nokia.meego 1.0

Dialog {
    id: root

    property string titleText
    property string description

    title: Label {
        text: titleText
        width: root.width
        font: UiConstants.TitleFont
    }
    content: Label {
        text: description
        width: root.width
        font: UiConstants.SmallTitleFont
    }
    buttons: Column {
        width: parent.width
        spacing: UiConstants.ButtonSpacing

        Button {
            text: qsTr("Yes")
            onClicked: root.accept();
            width: parent.width
        }
        Button {
            text: qsTr("No");
            onClicked: root.reject();
            width: parent.width
        }
    }
}
