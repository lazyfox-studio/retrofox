import thegamesdbapiservice


def find_game(api_key, path_to_game, platform):
    service = thegamesdbapiservice.TheGamesDBAPIService
    query_string = service.prepareQueryString(path_to_game)
    raw_games_data = service.loadRawGamesData(api_key, query_string, platform)
    if raw_games_data == None:
        return 1  # Request error
    games = service.extractGamesData(raw_games_data, query_string)
    if len(games) < 1:
        return 2  # Games not found
    # print(games)
    result = service.cacheGamesIntoDB(games, '../../sln/core/testbase.db')
    if not result:
        return 3  # Database error

find_game('445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600', 'D:/Games/(1996) Resident Evil[NTSC].cue', '10')
