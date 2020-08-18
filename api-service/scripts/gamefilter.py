import re


class GameFilter:
    @staticmethod
    def remove_sequels(games, query_string):
        delete_list = []
        if not re.search(r'\d', query_string):
            for game in games:
                if re.search(r'\d', game[1]):
                    delete_list.append(game)
            for game in delete_list:
                games.remove(game)
        return games

    @staticmethod
    def remove_editions(games):
        delete_list = []
        for game in games:
            if re.search(r'\(.*\)', game[1]):
                delete_list.append(game)
        for game in delete_list:
            games.remove(game)
        return games
