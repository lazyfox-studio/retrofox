import QtQuick 2.0
import QtQuick.Controls 2.15

SwipeView {
    Item {
        GameMenu {
            id: game_menu
            anchors.fill: parent
            focus: true
        }

        onFocusChanged: {
            if (focus) {
                game_menu.focus = true; //TODO: Improve focus receiving
            }
        }
    }

    Item {
        Text {
            text: "Setings"
        }
    }

    orientation: Qt.Vertical
    anchors.fill: parent

}
