import os
import re
import requests
import json
import sqlite3
from baseapiservice import BaseAPIService


class TheGamesDBAPIService(BaseAPIService):
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
            'fields': 'publishers,genres,overview',
            'filter[platform]': str(cls.local_platform_id['platform'])
        }
        answer = requests.get(cls.api_endpoint, params=request_params)
        return json.loads(answer.content)['data']

    @classmethod
    def extract_games_data(cls, raw_games_data, query_string=""):
        # Remove invalid games
        delete_list = []

        # Check if searching for first game in series
        if not raw_games_data['count'] == 1:
            if raw_games_data['count'] == 0:
                return 1
            if not re.search(r'\d', query_string):
                for game in raw_games_data['games']:
                    if re.search(r'\d', game['game_title']):
                        delete_list.append(game)
                        raw_games_data['count'] -= 1
        for game in delete_list:
            raw_games_data['games'].remove(game)
        delete_list = []

        # Remove all "xxx edition" from result
        if not raw_games_data['count'] == 1:
            if raw_games_data['count'] == 0:
                return 1
            for game in raw_games_data['games']:
                if re.search(r'\(.*\)', game['game_title']):
                    delete_list.append(game)
                    raw_games_data['count'] -= 1
        for game in delete_list:
            raw_games_data['games'].remove(game)
        delete_list = []

        # Preparing data for insertion
        # (name, platform_id, release_date, developer, publisher, genre, rating, description)
        games = []
        for game in raw_games_data['games']:
            games.append((game['game_title'], 0, game['release_date'], 0, 0, 0, 0, game['overview']))

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
            genres.append((genre['id'], genre['name']))

        # Adding data to database
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        cursor.execute('DROP TABLE IF EXISTS thegamesdb_genres')
        cursor.execute('CREATE TABLE thegamesdb_genres(id INT PRIMARY KEY, name TEXT)')
        cursor.executemany('INSERT INTO thegamesdb_genres VALUES (?,?)', genres)
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
            developers.append((developer['id'], developer['name']))

        # Adding data to database
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        cursor.execute('DROP TABLE IF EXISTS thegamesdb_developers')
        cursor.execute('CREATE TABLE thegamesdb_developers (id INT PRIMARY KEY, name TEXT)')
        cursor.executemany('INSERT INTO thegamesdb_developers VALUES (?,?)', developers)
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
            publishers.append((publisher['id'], publisher['name']))

        # Adding data to database
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        cursor.execute('DROP TABLE IF EXISTS thegamesdb_publishers')
        cursor.execute('CREATE TABLE thegamesdb_publishers (id INT PRIMARY KEY, name TEXT)')
        cursor.executemany('INSERT INTO thegamesdb_publishers VALUES (?,?)', publishers)
        base.commit()
        base.close()
