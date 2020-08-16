import json
import os
import re
import requests


def find_game(user_key, path):
    query_string = os.path.splitext(path)[0]
    query_string = os.path.basename(query_string)
    query_string = re.sub(r'\[.*\]', '', query_string)
    query_string = re.sub(r'\(.*\)', '', query_string)
    print(query_string)


find_game('445fcbc3f32bb2474bc27016b99eb963d318ee3a608212c543b9a79de1041600', 'D:/Games/(1996) Resident Evill [NTSC].cue')