import QtQuick 1.1
import com.nokia.meego 1.0
import Htsp 1.0

Sheet {
    id: root

    rejectButtonText: qsTr("Close")

    content: Flickable {
        anchors.fill: parent
        anchors.margins: UiConstants.DefaultMargin

        Column {
            width: root.width
            spacing: 15

            Column {
                spacing: 8
                Label {
                    text: qsTr("Server")
                    font: UiConstants.HeaderFont
                }

                Column {
                    Label {
                        text: qsTr("Name")
                        font: UiConstants.FieldLabelFont
                    }

                    Label {
                        text: htsp.serverName
                        font.pixelSize: 18
                    }
                }

                Column {
                    Label {
                        text: qsTr("Version")
                        font: UiConstants.FieldLabelFont
                    }

                    Label {
                        text: htsp.serverVersion
                        font.pixelSize: 18
                    }
                }

                Column {
                    Label {
                        text: qsTr("Protocol version")
                        font: UiConstants.FieldLabelFont
                    }

                    Label {
                        text: htsp.htspVersion
                        font.pixelSize: 18
                    }
                }

                Label {
                    text: qsTr("Connection")
                    font: UiConstants.HeaderFont
                }

                Column {
                    Label {
                        text: qsTr("Hostname")
                        font: UiConstants.FieldLabelFont
                    }

                    Label {
                        text: settings.hostname
                        font.pixelSize: 18
                    }
                }

                Column {
                    Label {
                        text: qsTr("Port")
                        font: UiConstants.FieldLabelFont
                    }

                    Label {
                        text: settings.port
                        font.pixelSize: 18
                    }
                }

                Column {
                    Label {
                        text: qsTr("Username")
                        font: UiConstants.FieldLabelFont
                    }

                    Label {
                        text: settings.username
                        font.pixelSize: 18
                    }
                }
            }
        }
    }

    onAccepted: close()
}
