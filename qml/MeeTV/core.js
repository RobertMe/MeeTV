function gotoPage(file) {
    var page = Qt.createComponent(file);
    return pageStack.push(page);
}

function viewChannel(channels, id) {
    var component = Qt.createComponent("ViewChannel.qml");
    var channel = channels.getChannelById(id);
    var page = component.createObject(pageStack, {"channel": channel, "events": channel.eventsModel});
    pageStack.push(page);
}

function viewDvrEntry(dvrEntries, id) {
    var component = Qt.createComponent("ViewDvrEntry.qml");
    var dvrEntry = dvrEntries.getDvrEntryById(id);
    var page = component.createObject(pageStack, {"dvrEntry": dvrEntry });
    pageStack.push(page);
}

function viewEvent(events, id) {
    var component = Qt.createComponent("ViewEvent.qml");
    var event = events.getEventById(id);
    var page = component.createObject(pageStack, {"event": event });
    pageStack.push(page);
}

function viewTag(tags, id) {
    var component = Qt.createComponent("BrowseChannels.qml");
    var tag = tags.getTagById(id);
    var page = component.createObject(pageStack, {"channels": tag.channelsModel });
    pageStack.push(page);
}

function searchEvent(parent, queryString, channelIndex, tagIndex)
{
    var epgQuery = Qt.createQmlObject('import QtQuick 1.0; import Htsp 1.0; EpgQuery { }', parent);
    epgQuery.query = queryString;
    if(channelIndex > 0)
        epgQuery.channel = channelDialog.model.getChannelByIndex(channelIndex);

    if(tagIndex > 0)
        epgQuery.tag = tagDialog.model.getTagByIndex(tagIndex);

    epgQuery.run();

    var component = Qt.createComponent("SearchEventResult.qml");
    var page = component.createObject(pageStack, {"events": epgQuery.eventsModel });
    pageStack.push(page);
}
