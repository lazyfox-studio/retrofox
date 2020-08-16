import requests
import json

headers = {"user-key": "58446688c5995387afb5a340e54ee0a5"}
data = "fields *; search \"Clock Tower\"; where platforms = (7);"

answer = requests.post("https://api-v3.igdb.com/games", headers=headers, data=data)
json_string = answer.content

games = json.loads(json_string)
for game in games:
    print(game["name"])
