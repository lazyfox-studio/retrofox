import QtQuick 2.0

ListView {
    Component {
        id: menu_delegate
        Card {
            width: 256; //TODO: Use not constant size of cards
            height: 288
            text: card_label
        }
    }

    model: ListModel {

        ListElement {
            card_label: "Resident Evil"
        }
        ListElement {
            card_label: "Silent Hill"
        }
        ListElement {
            card_label: "Ridge racer"
        }
        ListElement {
            card_label: "Tomb raider"
        }
        ListElement {
            card_label: "Driver 2"
        }
    }

    orientation: ListView.Horizontal
    delegate: menu_delegate
    highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
    focus: true
}
