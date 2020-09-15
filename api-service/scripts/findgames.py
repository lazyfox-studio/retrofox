from gamefilter import GameFilter
import os
import sqlite3
import thegamesdbapiservice


def scan_folder(path, extensions):
    roms = []
    for fs_object in os.listdir(path):
        if os.path.isdir(path + '/' + fs_object):
            roms.extend(scan_folder(path + '/' + fs_object, extensions))
        for extension in extensions:
            if fs_object.endswith(extension):
                roms.append(path + '/' + fs_object)
                break
    return roms


def find_games_in_folder(roms_path, platform_id, path_to_db):
    base = sqlite3.connect(path_to_db)
    cursor = base.cursor()
    # Reset records about games in search path
    cursor.execute('DELETE FROM games WHERE path LIKE ?', (roms_path + '%', ))

    # Saning
    cursor.execute('SELECT extension FROM extensions WHERE platform_id=?', (platform_id, ))
    extensions = cursor.fetchall()
    roms = scan_folder(roms_path, extensions)
    result_ids = []
    for rom in roms:
        cursor.execute('INSERT INTO games VALUES (NULL, ?, NULL, ?, NULL, NULL, NULL)', (rom, platform_id))
        result_ids.append(cursor.lastrowid)
    base.commit()
    base.close()
    return result_ids


def find_game(api_key, game_id, path_to_db):
    service = thegamesdbapiservice.TheGamesDBAPIService

    base = sqlite3.connect(path_to_db)
    cursor = base.cursor()
    cursor.execute('SELECT path, platform_id FROM games WHERE id = ?', (game_id, ))
    game_information = cursor.fetchone()
    path_to_game = game_information[0]
    platform = game_information[1]
    base.close()

    query_string = service.prepare_query_string(path_to_game)
    raw_games_data = service.load_raw_games_data(api_key, query_string, platform)
    if raw_games_data is None:
        return []  # Request error
    games = service.extract_games_data(raw_games_data, game_id, query_string)
    games = GameFilter.remove_sequels(games, query_string)
    games = GameFilter.remove_editions(games)
    games = GameFilter.remove_not_equality(games, query_string)
    if len(games) < 1:
        return []  # Games not found
    result = service.cache_games_into_db(games, path_to_db)
    if not result:
        return []  # Database error
    return result


def set_up_tables(path_to_db):
    service = thegamesdbapiservice.TheGamesDBAPIService
    service.set_up_tables(path_to_db)
    return 0

def list_test(roms_path, platform_id, path_to_db):
    return [1, 2, 3]


#thegamesdbapiservice.BaseAPIService.set_up_tables('D:/Source/retrofox/sln/core/testbase.db')
#find_games_in_folder('E:/Games/Emulators Library/PlayStation', 10, 'D:/Source/retrofox/sln/core/testbase.db')
#find_game('445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600', 1, 'D:/Source/retrofox/sln/core/testbase.db')

#thegamesdbapiservice.TheGamesDBAPIService.update_genres('445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600', 'D:/Source/retrofox/sln/core/testbase.db')
