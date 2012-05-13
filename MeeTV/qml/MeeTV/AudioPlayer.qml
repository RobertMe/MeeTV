import QtQuick 1.1
import com.nokia.meego 1.0
import QtMultimediaKit 1.1
import Htsp 1.0

Page {
    property Channel channel

    tools: CommonToolbar {
        ToolIcon {
            id: stopIcon
            iconId: "toolbar-mediacontrol-stop"
            onClicked: { player.stop(); pageStack.pop(); }
            anchors.left: parent.backIcon.right
        }
    }

    Audio {
        id: player

        autoLoad: true

        source: htsp.getStreamUrl(channel)
        Component.onCompleted: { play(); }
    }
}
