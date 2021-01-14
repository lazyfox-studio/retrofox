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

        font.pixelSize: height * (3 / 5)
        elide: Text.ElideRight
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
