import os
import re
import requests
import json
import sqlite3
from baseapiservice import BaseAPIService


class IGDBAPIService(BaseAPIService):
    api_endpoint = 'https://api-v3.igdb.com/games'

    @classmethod
    def loadRawGamesData(cls, api_key, query_string, platform):
        headers = {"user-key": "58446688c5995387afb5a340e54ee0a5"}
        data = "fields *; search \"Clock Tower\"; where platforms = (7);"
        answer = requests.post(cls.api_endpoint, headers=headers, data=data)
        return json.loads(answer.content)
    
    @classmethod
    def extractGamesData(cls, raw_games_data, query_string=""):
        raise NotImplementedError
