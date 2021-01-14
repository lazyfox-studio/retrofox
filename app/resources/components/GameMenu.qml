import QtQuick 2.0
import Database 1.0

ListView {
    Database {
        id: database
        db_name: "testbase"
    }

    Component {
        id: menu_delegate
        Card {
            width: 256; //TODO: Use not constant size of cards
            height: 288
            name: label
        }
    }

    model: ListModel {
        id: list_model
    }

    orientation: ListView.Horizontal
    delegate: menu_delegate
    highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
    focus: true

    Component.onCompleted: {
        let games = database.query("SELECT * FROM games");
        games.forEach(function(game) {
            list_model.append({label: game.name});
        });
    }
}
