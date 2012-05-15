function gotoPage(file) {
    return pageStack.push(Qt.resolvedUrl(file));
}

function viewChannel(channel) {
    var item = pageStack.push(Qt.resolvedUrl("ViewChannel.qml"),
                   {"channel": channel, "events": channel.eventsModel});
    channel.parent = item;
}

function viewDvrEntry(dvrEntry) {
    var item = pageStack.push(Qt.resolvedUrl("ViewDvrEntr.qml"), {"dvrEntry": dvrEntry });
    dvrEntry.parent = item;
}

function viewEvent(event) {
    var item = pageStack.push(Qt.resolvedUrl("ViewEvent.qml"), {"event": event});
    event.parent = item;
}

function viewTag(tag) {
    var item = pageStack.push(Qt.resolvedUrl("BrowseChannels.qml"), {"tag": tag });
    tag.parent = item;
}

function searchEvent(parent, queryString, channel, tag)
{
    var epgQuery = Qt.createQmlObject('import QtQuick 1.0; import Htsp 1.0; EpgQuery { }', parent);
    epgQuery.query = queryString;
    epgQuery.channel = channel;
    epgQuery.tag = tag;
    epgQuery.run();

    var item = pageStack.push(Qt.resolvedUrl("SearchEventResult.qml"), {"events": epgQuery.eventsModel });
    epgQuery.parent = item;
}
