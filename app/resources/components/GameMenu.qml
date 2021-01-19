import QtQuick 2.0
import Database 1.0
import Executor 1.0

ListView {
    Database {
        id: database
        db_name: "testbase"
    }

    Executor {
        id: executor
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
    highlightMoveDuration: 250
    highlightMoveVelocity: -1

    Component.onCompleted: {
        let games = database.query("SELECT * FROM games");
        games.forEach(function(game) {
            list_model.append({card_game_id: game.id, card_name: game.name, card_path: game.path,
                              card_platform_id: game.platform_id, card_cover: ""});
        });
    }

    Keys.onPressed: {
        if (event.key === Qt.Key_Space) {
            event.accepted = true
            let emulator_id = database.query("SELECT default_emulator_id FROM platforms where id = %1"
                                      .arg(currentItem.platform_id))[0].default_emulator_id;
            let emulator = database.query("SELECT * FROM emulators where id = %1".arg(emulator_id))[0];
            let execution_command = emulator.emulator_path + " " + emulator.execution_parameters;
            // Replace all variables here
            execution_command = execution_command.replace("%ROM%", currentItem.path);
            console.debug(execution_command);
            executor.start(execution_command);
        }
    }
}
