import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Hello World")



    SwipeView {
        Item {
            Text {
                text: "Setings"
            }
        }

        Item {
            GameView {
                id: game_view
            }

            onFocusChanged: {
                if (focus) {
                    game_view.focus = true; //TODO: Improve focus receiving
                }
            }
        }

        orientation: Qt.Vertical
        anchors.fill: parent
        focus: true
    }
}
