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
            games.append(
                (game['game_title'], game['release_date'], 0, 0, 0, game['overview']))

        return games
