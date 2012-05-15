function gotoPage(file) {
    return pageStack.push(Qt.resolvedUrl(file));
}

function viewChannel(channel) {
    pageStack.push(Qt.resolvedUrl("ViewChannel.qml"),
                   {"channel": channel, "events": channel.eventsModel});
}

function viewDvrEntry(dvrEntry) {
    pageStack.push(Qt.resolvedUrl("ViewDvrEntr.qml"), {"dvrEntry": dvrEntry });
}

function viewEvent(event) {
    pageStack.push(Qt.resolvedUrl("ViewEvent.qml"), {"event": event});
}

function viewTag(tag) {
    pageStack.push(Qt.resolvedUrl("BrowseChannels.qml"), {"tag": tag });
}

function searchEvent(parent, queryString, channel, tag)
{
    var epgQuery = Qt.createQmlObject('import QtQuick 1.0; import Htsp 1.0; EpgQuery { }', parent);
    epgQuery.query = queryString;
    epgQuery.channel = channel;
    epgQuery.tag = tag;
    epgQuery.run();

    pageStack.push(Qt.resolvedUrl("SearchEventResult.qml"), {"events": epgQuery.eventsModel });
}
