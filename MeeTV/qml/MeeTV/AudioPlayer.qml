import QtQuick 1.1
import com.nokia.meego 1.0
import QtMultimediaKit 1.1
import Htsp 1.0

Page {
    property Channel channel

    tools: CommonToolbar {
    }

    Audio {
        autoLoad: true

        source: htsp.getStreamUrl(channel)
        Component.onCompleted: { play(); }
    }
}
