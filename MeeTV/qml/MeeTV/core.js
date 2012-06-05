function gotoPage(file) {
    return pageStack.push(Qt.resolvedUrl(file));
}

function replaceChannel(channel, model, index) {
    var item = pageStack.replace(Qt.resolvedUrl("ViewChannel.qml"),
                                 {"channel": channel, "events": channel.eventsModel,
                                 "channelModel": model, "currentIndex": index});
    channel.parent = item;
}

function viewChannel(channel, model, index) {
    var item = pageStack.push(Qt.resolvedUrl("ViewChannel.qml"),
                   {"channel": channel, "events": channel.eventsModel,
                                  "channelModel": model, "currentIndex": index});
    channel.parent = item;
}

function viewDvrEntry(dvrEntry) {
    var item = pageStack.push(Qt.resolvedUrl("ViewDvrEntry.qml"), {"dvrEntry": dvrEntry });
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
