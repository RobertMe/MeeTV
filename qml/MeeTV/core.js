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
