function gotoPage(file) {
    var page = Qt.createComponent(file);
    return pageStack.push(page);
}

function viewChannel(channel) {
    var component = Qt.createComponent("ViewChannel.qml");
    var page = component.createObject(pageStack, {"channel": channel, "events": channel.eventsModel});
    pageStack.push(page);
}

function viewDvrEntry(dvrEntry) {
    var component = Qt.createComponent("ViewDvrEntry.qml");
    var page = component.createObject(pageStack, {"dvrEntry": dvrEntry });
    pageStack.push(page);
}

function viewEvent(event) {
    var component = Qt.createComponent("ViewEvent.qml");
    var page = component.createObject(pageStack, {"event": event });
    pageStack.push(page);
}

function viewTag(tag) {
    var component = Qt.createComponent("BrowseChannels.qml");
    var page = component.createObject(pageStack, {"tag": tag });
    pageStack.push(page);
}

function searchEvent(parent, queryString, channel, tag)
{
    var epgQuery = Qt.createQmlObject('import QtQuick 1.0; import Htsp 1.0; EpgQuery { }', parent);
    epgQuery.query = queryString;
    epgQuery.channel = channel;
    epgQuery.tag = tag;
    epgQuery.run();

    var component = Qt.createComponent("SearchEventResult.qml");
    var page = component.createObject(pageStack, {"events": epgQuery.eventsModel });
    pageStack.push(page);
}
