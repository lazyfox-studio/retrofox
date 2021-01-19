import QtQuick 2.0
import QtQuick.Controls 2.15

SwipeView {
    Item {
        GameMenu {
            id: game_menu
            anchors.fill: parent
            focus: true

            onCurrentItemChanged: {
                game_info.setGame(currentItem)
            }
        }

        onFocusChanged: {
            if (focus) {
                game_menu.focus = true; //TODO: Improve focus receiving
            }
        }
    }

    Item {
        GameInfo {
            id: game_info
        }
    }

    orientation: Qt.Vertical
    anchors.fill: parent

}
