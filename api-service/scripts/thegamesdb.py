import json
import os
import re
import requests


def find_game(api_key, path, platform):
    #Preparing query
    query_string = os.path.splitext(path)[0]
    query_string = os.path.basename(query_string)
    query_string = re.sub(r'\[.*\]', '', query_string)
    query_string = re.sub(r'\(.*\)', '', query_string)
    if query_string.startswith(" "):
        query_string = query_string[1:]
    print(query_string)

    #Sending request
    queary_params = {
        'apikey': api_key,
        'name': query_string,
        'platfrom': platform
    }
    answer = requests.get("https://api.thegamesdb.net/v1.1/Games/ByGameName", params=queary_params)
    games = json.loads(answer.content)['data']

    #Remove invaild games
    delete_list = []

    #Chck if seraching for first game in series
    if not games['count'] == 1:
        if (games['count'] == 0):
            return 1
        if not re.search(r'\d', query_string):
            for game in games['games']:
                if re.search(r'\d', game['game_title']):
                    delete_list.append(game)
                    games['count'] -= 1
    for game in delete_list:
        games['games'].remove(game)
    delete_list = []

    #Remove all "xxx edition" from result
    if not games['count'] == 1:
        if (games['count'] == 0):
            return 1
        for game in games['games']:
            if re.search(r'\(.*\)', game['game_title']):
                delete_list.append(game)
                games['count'] -= 1
    for game in delete_list:
        games['games'].remove(game)
    delete_list = []

    games = games['games']

    print(games)
    #Add to database


find_game('445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600', 'D:/Games/(1996) Resident Evil[NTSC].cue', '10')