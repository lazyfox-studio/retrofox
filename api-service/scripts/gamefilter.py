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

    @staticmethod
    def remove_not_equality(games, query_string):
        output = []
        for game in games:
            if game[1].capitalize() == query_string.capitalize():
                output.append(game)
        if len(output) > 0:
            return output
        else:
            return games
