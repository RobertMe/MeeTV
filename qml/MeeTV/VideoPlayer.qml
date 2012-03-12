import QtQuick 1.1
import com.nokia.meego 1.0
import QtMultimediaKit 1.1
import "core.js" as Core

Page {
    //property alias player: player

    tools: commonTools

    Video {
        id: player
        //source: "http://hts:hts@192.168.2.14:9981/stream/channelid/64"

        anchors.fill: parent
        playing: true
    }
}
