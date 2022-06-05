import ast
import json


class FileReader:
    @staticmethod
    def read_from_file(file_name: str):
        names = []
        balances = []
        card = json.load(open(file_name, "r"))
        for user in card:
            names.append(user["name"])
            balances.append(user["balances"])
        return names, balances


