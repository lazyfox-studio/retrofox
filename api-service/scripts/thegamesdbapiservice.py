import requests
import json
import sqlite3
from baseapiservice import BaseAPIService


class TheGamesDBAPIService(BaseAPIService):
    base_prefix = 1

    api_endpoint = 'https://api.thegamesdb.net/v1.1/Games/ByGameName'

    local_platform_id = {
        1: 1, 2: 2, 3: 3, 4: 4, 5: 5, 6: 6, 7: 7, 8: 8, 9: 9, 10: 10,
        11: 11, 12: 12, 13: 13, 14: 14, 15: 15, 16: 16, 17: 17, 18: 18, 19: 19, 20: 20,
        21: 21, 22: 22, 23: 23, 24: 24, 25: 25, 26: 26, 27: 27, 28: 28, 29: 29, 30: 30,
        31: 31, 32: 32, 33: 33, 34: 34, 35: 35, 36: 36, 37: 37, 38: 38, 39: 39, 40: 40,
        41: 41
        # TODO: Add more
    }

    @classmethod
    def load_raw_games_data(cls, api_key, query_string, platform):
        request_params = {
            'apikey': api_key,
            'name': query_string,
            'fields': 'publishers,genres,overview,rating',
            'filter[platform]': str(cls.local_platform_id[platform])
        }
        answer = requests.get(cls.api_endpoint, params=request_params)
        return json.loads(answer.content)['data']

    @classmethod
    def extract_games_data(cls, raw_games_data, game_id, query_string):
        for game in raw_games_data['games']:
            for developer in game['developers']:
                developer += cls.base_prefix * cls.prefix_order
            for publisher in game['publishers']:
                publisher += cls.base_prefix * cls.prefix_order
            for genre in game['genres']:
                genre += cls.base_prefix * cls.prefix_order

        games = []
        for game in raw_games_data['games']:
            games.append(
                {
                    'game': (game_id, game['game_title'], game['release_date'], game['rating'], game['overview']),
                    'developers': game['developers'],
                    'publishers': game['publishers'],
                    'genres': game['genres']
                }
            )
        return games

    @classmethod
    def update_genres(cls, api_key, path_to_db):
        # Sending request
        request_params = {
            'apikey': api_key
        }
        answer = requests.get('https://api.thegamesdb.net/v1/Genres', params=request_params)
        raw_genres_data = json.loads(answer.content)['data']['genres'].values()

        # Preparing data for insertion
        genres = []
        for genre in raw_genres_data:
            genres.append((genre['id'] + cls.base_prefix * cls.prefix_order, genre['name']))

        # Adding data to database
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        cursor.execute('CREATE TABLE IF NOT EXISTS genres(id INTEGER PRIMARY KEY, name TEXT)')
        cursor.execute('DELETE FROM genres WHERE (id / ?) == ?', (cls.prefix_order, cls.base_prefix))
        cursor.executemany('INSERT INTO genres VALUES (?,?)', genres)
        base.commit()
        base.close()

    @classmethod
    def update_developers(cls, api_key, path_to_db):
        # Sending request
        request_params = {
            'apikey': api_key
        }
        answer = requests.get('https://api.thegamesdb.net/v1/Developers', params=request_params)
        raw_developers_data = json.loads(answer.content)['data']['developers'].values()

        # Preparing data for insertion
        developers = []
        for developer in raw_developers_data:
            developers.append((developer['id'] + cls.base_prefix * cls.prefix_order, developer['name']))

        # Adding data to database
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        cursor.execute('CREATE TABLE IF NOT EXISTS developers (id INTEGER PRIMARY KEY, name TEXT)')
        cursor.execute('DELETE FROM developers WHERE (id / ?) == ?', (cls.prefix_order, cls.base_prefix))
        cursor.executemany('INSERT INTO developers VALUES (?,?)', developers)
        base.commit()
        base.close()

    @classmethod
    def update_publishers(cls, api_key, path_to_db):
        # Sending request
        request_params = {
            'apikey': api_key
        }
        answer = requests.get('https://api.thegamesdb.net/v1/Publishers', params=request_params)
        raw_publishers_data = json.loads(answer.content)['data']['publishers'].values()

        # Preparing data for insertion
        publishers = []
        for publisher in raw_publishers_data:
            publishers.append((publisher['id'] + cls.base_prefix * cls.prefix_order, publisher['name']))

        # Adding data to database
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        cursor.execute('CREATE TABLE IF NOT EXISTS publishers (id INTEGER PRIMARY KEY, name TEXT)')
        cursor.execute('DELETE FROM publishers WHERE (id / ?) == ?', (cls.prefix_order, cls.base_prefix))
        cursor.executemany('INSERT INTO publishers VALUES (?,?)', publishers)
        base.commit()
        base.close()
