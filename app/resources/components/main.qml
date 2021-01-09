import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent

        Component {
            id: contactDelegate
            Item {
                width: 256; height: 288
                Text {
                    id: card_label
                    width: parent.width
                    height: 32

                    text: game_label
                    font.pointSize: 24
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.top: parent.top
                }
                Image {
                    id: card_icon
                    source: "/textures/blank.svg"
                    sourceSize.width: 256
                    sourceSize.height: 256
                    anchors.bottom: parent.bottom
                }
            }
        }

        ListView {
            anchors.fill: parent
            model: ListModel {

                ListElement {
                    game_label: "Resident Evil"
                }
                ListElement {
                    game_label: "Silent Hill"
                }
                ListElement {
                    game_label: "Ridge racer"
                }
                ListElement {
                    game_label: "Tomb raider"
                }
                ListElement {
                    game_label: "Driver 2"
                }
            }
            orientation: ListView.Horizontal
            delegate: contactDelegate
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            focus: true
        }
    }
}
