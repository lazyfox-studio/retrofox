import requests

headers = {"user-key": "58446688c5995387afb5a340e54ee0a5"}
data = "fields *; search \"Clock Tower\"; where platforms = (58);"

answer = requests.post("https://api-v3.igdb.com/games", headers=headers, data=data)
print(answer.content)