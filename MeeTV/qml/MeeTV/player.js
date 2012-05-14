function playChannel(channel)
{
    if(appProperties.currentPlayer)
        appProperties.currentPlayer.destroy();

    var component = Qt.createComponent(channel.service.type == Service.RadioType ? "AudioPlayer.qml" : "VideoPlayer.qml");
    appProperties.currentPlayer = component.createObject(pageStack, {"channel": channel});
    appProperties.currentPlayer.parent = pageStack.parent
    pageStack.push(appProperties.currentPlayer);
    mainOptions.get(3).hide = false;
}

function reopenPlayer()
{
    pageStack.push(appProperties.currentPlayer);
}

function stopPlayer()
{
    player.stop();
    pageStack.pop();
    mainOptions.get(3).hide = true;
}
