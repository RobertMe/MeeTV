function gotoPage(file) {
    return pageStack.push(Qt.resolvedUrl(file));
}

function viewChannel(channel, model, index, replace) {
    var page = Qt.resolvedUrl("ViewChannel.qml");
    var params = {"channel": channel, "events": channel.eventsModel,
        "channelModel": model, "currentIndex": index};
    var item;
    if(replace)
        item = pageStack.replace(page, params);
    else
        item = pageStack.push(page, params);
    channel.parent = item;
}

function viewDvrEntry(dvrEntry) {
    var item = pageStack.push(Qt.resolvedUrl("ViewDvrEntry.qml"), {"dvrEntry": dvrEntry });
    dvrEntry.parent = item;
}

function viewEvent(event, allowNavigate, replace) {
    var page = Qt.resolvedUrl("ViewEvent.qml");
    var params = {"event": event, "allowNavigate": !!allowNavigate};
    var item;
    if(replace)
        item = pageStack.replace(page, params);
    else
        item = pageStack.push(page, params);
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

function searchOnImdb(event)
{
    Qt.openUrlExternally("http://m.imdb.com/find?q=" + event.title)
}
