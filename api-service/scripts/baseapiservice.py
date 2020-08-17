import os
import re
import requests
import json
import sqlite3


class BaseAPIService(object):
    api_endpoint = ''

    @classmethod
    def prepareQueryString(cls, path_to_game):
        query_string = os.path.splitext(path_to_game)[0]
        query_string = os.path.basename(query_string)
        query_string = re.sub(r'\[.*\]', '', query_string)
        query_string = re.sub(r'\(.*\)', '', query_string)
        query_string = query_string.strip()
        return query_string

    @classmethod
    def loadRawGamesData(cls, api_key, query_string, platform):
        raise NotImplementedError
    
    @classmethod
    def extractGamesData(cls, raw_games_data, query_string):
        raise NotImplementedError
    
    @classmethod
    def cacheGamesIntoDB(cls, games, path_to_db):
        # base = sqlite3.connect(path_to_db)
        # cursor = base.cursor()
        # cursor.executemany('INSERT INTO scraper_cache VALUES (?,?,?,?,?,?)', games)
        return True

