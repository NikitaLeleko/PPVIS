class NotEnoughMoneyException(Exception):
    def __init__(self, *args):
        if args:
            self.massage = args[0]
        else:
            self.massage = "NOT ENOUGH MONEY"

    def __str__(self):
        return self.massage
