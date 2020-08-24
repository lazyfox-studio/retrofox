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
    return roms


def find_games_in_folder(roms_path, platform, path_to_db):
    base = sqlite3.connect(path_to_db)
    cursor = base.cursor()
    cursor.execute('SELECT extension FROM extensions WHERE platform_id=?', (platform, ))
    extensions = cursor.fetchall()
    roms = scan_folder(roms_path, extensions)
    for rom in roms:
        cursor.execute('INSERT INTO games VALUES (NULL, ?, NULL, ?, NULL, NULL, NULL, NULL)', (rom, platform))
    base.commit()
    base.close()


def find_game(api_key, game_id, path_to_db):
    service = thegamesdbapiservice.TheGamesDBAPIService

    base = sqlite3.connect(path_to_db)
    cursor = base.cursor()
    cursor.execute('SELECT path, platform_id FROM games WHERE id = game_id')
    game_information = cursor.fetchone()
    path_to_game = game_information[0]
    platform = game_information[1]
    base.close()

    query_string = service.prepare_query_string(path_to_game)
    raw_games_data = service.load_raw_games_data(api_key, query_string, platform)
    if raw_games_data == None:
        return 1  # Request error
    games = service.extract_games_data(raw_games_data, game_id, query_string, '../../sln/core/testbase.db')
    games = GameFilter.remove_sequels(games, query_string)
    games = GameFilter.remove_editions(games)
    games = GameFilter.remove_not_equality(games, query_string)
    if len(games) < 1:
        return 2  # Games not found
    # print(games)
    result = service.cache_games_into_db(games, '../../sln/core/testbase.db')
    if not result:
        return 3  # Database error


thegamesdbapiservice.BaseAPIService.set_up_tables('E:/Source/retrofox/sln/core/testbase.db')
#find_games_in_folder('Z:\PlayStation', 10, 'E:/Source/retrofox/sln/core/testbase.db')
#find_game('445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600', 1, 'E:/Source/retrofox/sln/core/testbase.db')

#thegamesdbapiservice.TheGamesDBAPIService.update_genres('445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600', 'E:/Source/retrofox/sln/core/testbase.db')
