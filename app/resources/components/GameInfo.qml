import QtQuick 2.0

Item {
    anchors.fill: parent

    Text {
        id: name
    }

    function setGame(game) {
        name.text = game.name
    }
}
