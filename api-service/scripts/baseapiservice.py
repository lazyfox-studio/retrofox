import os
import re
import requests
import json
import sqlite3


class BaseAPIService:
    api_endpoint = ''

    @classmethod
    def prepare_query_string(cls, path_to_game):
        query_string = os.path.splitext(path_to_game)[0]
        query_string = os.path.basename(query_string)
        query_string = re.sub(r'\[.*\]', '', query_string)
        query_string = re.sub(r'\(.*\)', '', query_string)
        query_string = query_string.strip()
        return query_string

    @classmethod
    def load_raw_games_data(cls, api_key, query_string, platform):
        raise NotImplementedError
    
    @classmethod
    def extract_games_data(cls, raw_games_data, query_string):
        raise NotImplementedError
    
    @classmethod
    def cache_games_into_db(cls, games, path_to_db):
        # base = sqlite3.connect(path_to_db)
        # cursor = base.cursor()
        # cursor.executemany('INSERT INTO scraper_cache VALUES (?,?,?,?,?,?)', games)
        return True

