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
            width:  256 //TODO: Use not constant size of cards
            height: 288
            game_id:     card_game_id
            name:        card_name
            path:        card_path
            platform_id: card_platform_id
            cover:       card_cover
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
            list_model.append({card_game_id: game.id, card_name: game.name, card_path: game.path,
                              card_platform_id: game.platform_id, card_cover: ""});
        });
    }
}
