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
    def extract_games_data(cls, raw_games_data, query_string, path_to_db):
        raise NotImplementedError
    
    @classmethod
    def cache_games_into_db(cls, games, path_to_db):
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        cursor.executemany('INSERT INTO scraper_cache_games VALUES (NULL,?,?,?,?,?,?,?,?)', games)
        base.commit()
        base.close()
        return True

    @classmethod
    def set_up_table(cls, path_to_db):
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        cursor.execute('CREATE TABLE IF NOT EXISTS scraper_cache_games'
                       '(id INTEGER PRIMARY KEY, name TEXT, platform_id INTEGER, release_date TEXT,'
                       ' developer TEXT, publisher TEXT, genre TEXT, rating TEXT, description TEXT)')
        base.commit()
        base.close()

    @classmethod
    def update_genres(cls, api_key, path_to_db):
        raise NotImplementedError

    @classmethod
    def update_developers(cls, api_key, path_to_db):
        raise NotImplementedError

    @classmethod
    def update_publishers(cls, api_key, path_to_db):
        raise NotImplementedError