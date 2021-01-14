import QtQuick 2.0

Item {
    property alias game_id:     game.game_id
    property alias name:        game.name
    property alias path:        game.path
    property alias platform_id: game.platform_id
    property alias cover:       game.cover


    Text {
        id: label
        text: (game.name == "") ? "Game" : game.name

        wrapMode: Text.WordWrap
        clip: true
        font.pixelSize: height * (1 / 2)
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.bottom: icon.top
        anchors.left: parent.left
        anchors.right:parent.right
    }
    Image {
        id: icon
        source: (game.cover == "") ? "qrc:/assets/blank.svg" : game.cover

        sourceSize.width: parent.width
        sourceSize.height: parent.width
        anchors.bottom: parent.bottom
    }

    Game {
        id: game
    }
}
