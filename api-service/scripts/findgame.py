import thegamesdbapiservice


def find_game(api_key, path_to_game, platform):
    service = thegamesdbapiservice.TheGamesDBAPIService
    query_string = service.prepare_query_string(path_to_game)
    raw_games_data = service.load_raw_games_data(api_key, query_string, platform)
    if raw_games_data == None:
        return 1  # Request error
    games = service.extract_games_data(raw_games_data, query_string, '../../sln/core/testbase.db')
    if len(games) < 1:
        return 2  # Games not found
    # print(games)
    result = service.cache_games_into_db(games, '../../sln/core/testbase.db')
    if not result:
        return 3  # Database error

# thegamesdbapiservice.BaseAPIService.set_up_table('E:/Source/retrofox/sln/core/testbase.db')
find_game('445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600', 'D:/Games/(1996) Resident Evil[NTSC].cue', 10)

# thegamesdbapiservice.TheGamesDBAPIService.update_publishers('445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600', 'D:/Source/retrofox/sln/core/testbase.db')
