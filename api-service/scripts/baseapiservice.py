import os
import re
import requests
import json
import sqlite3


class BaseAPIService:
    prefix_order = 1000000
    api_endpoint = ''

    standard_extensions = [
        (10, 'cue'), (10, 'CUE')
    ]

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
    def extract_games_data(cls, raw_games_data, game_id, query_string):
        raise NotImplementedError
    
    @classmethod
    def cache_games_into_db(cls, games, path_to_db):
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        result = []
        for game in games:
            cursor.execute('INSERT INTO scraper_cache_games VALUES (NULL,?,?,?,?,?)', game['game'])
            cache_id = cursor.lastrowid
            if not game['developers'] is None:
                for developer in game['developers']:
                    cursor.execute('INSERT INTO scraper_cache_developers VALUES (?,?)', (cache_id, developer))
            if not game['publishers'] is None:
                for publisher in game['publishers']:
                    cursor.execute('INSERT INTO scraper_cache_publishers VALUES (?,?)', (cache_id, publisher))
            if not game['developers'] is None:
                for genre in game['genres']:
                    cursor.execute('INSERT INTO scraper_cache_genres VALUES (?,?)', (cache_id, genre))
            result.append(cache_id)
        base.commit()
        base.close()
        return result

    @classmethod
    def set_up_tables(cls, path_to_db):
        base = sqlite3.connect(path_to_db)
        cursor = base.cursor()
        # Game information table
        cursor.execute('CREATE TABLE IF NOT EXISTS games'
                       '(id INTEGER PRIMARY KEY, path TEXT, name TEXT, platform_id INTEGER NOT NULL, release_date TEXT,'
                       'rating TEXT, description TEXT)')
        # Developer information table
        cursor.execute('CREATE TABLE IF NOT EXISTS developers'
                       '(game_id INTEGER NOT NULL, developer_id INTEGER NOT NULL)')
        # Publisher information table
        cursor.execute('CREATE TABLE IF NOT EXISTS publishers'
                       '(game_id INTEGER NOT NULL, publisher_id INTEGER NOT NULL)')
        # Genre information table
        cursor.execute('CREATE TABLE IF NOT EXISTS genres'
                       '(game_id INTEGER NOT NULL, genre_id INTEGER NOT NULL)')
        # Rom extensions information table
        cursor.execute('CREATE TABLE IF NOT EXISTS extensions'
                       '(platform_id INTEGER NOT NULL, extension TEXT)')
        cursor.executemany('INSERT INTO extensions VALUES (?, ?)', cls.standard_extensions)

        # Scraper cache tables
        cursor.execute('CREATE TABLE IF NOT EXISTS scraper_cache_games'
                       '(id INTEGER PRIMARY KEY, game_id INTEGER NOT NULL, name TEXT, release_date TEXT,'
                       ' rating TEXT, description TEXT)')
        cursor.execute('CREATE TABLE IF NOT EXISTS scraper_cache_developers'
                       '(cache_id INTEGER NOT NULL, developer_id INTEGER NOT NULL)')
        cursor.execute('CREATE TABLE IF NOT EXISTS scraper_cache_publishers'
                       '(cache_id INTEGER NOT NULL, publisher_id INTEGER NOT NULL)')
        cursor.execute('CREATE TABLE IF NOT EXISTS scraper_cache_genres'
                       '(cache_id INTEGER NOT NULL, genre_id INTEGER NOT NULL)')
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
