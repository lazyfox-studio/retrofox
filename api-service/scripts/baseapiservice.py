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
    def extract_games_data(cls, raw_games_data, game_id, query_string, path_to_db):
        raise NotImplementedError
    
    @classmethod
    def cache_games_into_db(cls, games, path_to_db):
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        for game in games:
            cursor.execute('INSERT INTO scraper_cache_games VALUES (NULL,?,?,?,?,?)', game['game'])
            cache_id = cursor.lastrowid
            for developer in game['developers']:
                cursor.execute('INSERT INTO scraper_cache_developers VALUES (?,?)', (cache_id, developer))
            for publisher in game['publishers']:
                cursor.execute('INSERT INTO scraper_cache_publishers VALUES (?,?)', (cache_id, publisher))
            for genre in game['genres']:
                cursor.execute('INSERT INTO scraper_cache_genres VALUES (?,?)', (cache_id, genre))
        base.commit()
        base.close()
        return True

    @classmethod
    def set_up_table(cls, path_to_db):
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        cursor.execute('CREATE TABLE IF NOT EXISTS scraper_cache_games'
                       '(id INTEGER PRIMARY KEY,game_id INTEGER NOT NULL, name TEXT, release_date TEXT,'
                       ' rating TEXT, description TEXT)')
        cursor.execute('CREATE TABLE IF NOT EXISTS scraper_cache_developers'
                       '(cache_id INTEGER NOT NULL, developer TEXT)')
        cursor.execute('CREATE TABLE IF NOT EXISTS scraper_cache_publishers'
                       '(cache_id INTEGER NOT NULL, publisher TEXT)')
        cursor.execute('CREATE TABLE IF NOT EXISTS scraper_cache_genres'
                       '(cache_id INTEGER NOT NULL, genre TEXT)')
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