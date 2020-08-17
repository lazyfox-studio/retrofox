import os
import re
import requests
import json
import sqlite3
from baseapiservice import BaseAPIService


class TheGamesDBAPIService(BaseAPIService):
    api_endpoint = 'https://api.thegamesdb.net/v1.1/Games/ByGameName'

    @classmethod
    def load_raw_games_data(cls, api_key, query_string, platform):
        request_params = {
            'apikey': api_key,
            'name': query_string,
            'fields': 'publishers,genres,overview',
            'filter[platform]': platform
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
        # (name, platform_id, developer, publisher, release_date, genre, rating, description, boxart)
        games = []
        for game in raw_games_data['games']:
            games.append((game['game_title'], game['release_date'], 0, 0, 0, game['overview']))

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
