import QtQuick 1.1
import com.nokia.meego 1.0
import QtMultimediaKit 1.1
import "player.js" as Player
import Htsp 1.0

Page {
    property Channel channel

    tools: CommonToolbar {
        ToolIcon {
            id: stopIcon
            iconId: "toolbar-mediacontrol-stop"
            onClicked: { Player.stopPlayer(); }
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
