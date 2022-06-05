from typing import List, TypeGuard, Dict

from .Bank import Bank
from .Banknote import Banknote
from .Card import Card


class ATM:
    def __init__(self):
        self.__cash_holder = {}
        self.inserted_card = None

    @property
    def cash_holder(self):
        return self.__cash_holder

    @staticmethod
    def give_cash(currency: str, how_much: int) -> List[Banknote]:
        nominal_values = [100, 50, 20, 10, 5, 1]
        result = []
        for nominal in nominal_values:
            if nominal <= how_much:
                amount_of_banknotes = how_much // nominal
                for _ in range(amount_of_banknotes):
                    result.append(Banknote(currency, nominal))
                how_much -= amount_of_banknotes * nominal
        return result

    def add_money_to_cash_holder(self, money: Dict[str, int]) -> None:
        for nominal, amount in money.items():
            if nominal not in self.__cash_holder:
                self.__cash_holder[nominal] = amount
            else:
                self.__cash_holder[nominal] += amount

    def insert_card(self, card: Card) -> str:
        if self.inserted_card is not None:
            return "Card is not inserted"

        self.inserted_card = card
        return "your card was successfully inserted"

    def check_card(self) -> TypeGuard:
        if self.inserted_card is None:
            print("Card is not inserted")
            return False

        if not self.inserted_card.active:
            print("Card Is Blocked")
            return False

        if not Bank.find_card(self.inserted_card):
            return False

        if not self.inserted_card.check_password():
            return False

        return True

    def withdraw_money(self, currency: str, cash: int) -> List[Banknote]:
        if currency not in self.inserted_card.balance.keys():
            print("YOU DO NOT HAVE SUCH CURRENCY ON THE CARD")
            return []

        if currency not in self.__cash_holder.keys():
            print("WE DO NOT HAVE SUCH CURRENCY IN THE ATM")
            return []

        if self.inserted_card.balance[currency] < cash:
            print("NOT ENOUGH MONEY ON YOUR CARD")
            return []

        if self.__cash_holder[currency] < cash:
            print("NOT ENOUGH MONEY IN THE ATM")
            return []

        self.inserted_card.balance[currency] -= cash
        self.__cash_holder[currency] -= cash

        res = ATM.give_cash(currency, cash)
        return res

    def show_balance(self) -> Dict[str, int]:
        return self.inserted_card.balance

    def top_up_phone_balance(self, phone_number: str, currency: str, cash: int) -> str:
        if currency not in self.inserted_card.balance.keys():
            return "YOU DO NOT HAVE SUCH CURRENCY ON THE CARD"

        if self.inserted_card.balance[currency] < cash:
            return "NOT ENOUGH MONEY ON YOUR CARD"

        self.inserted_card.balance[currency] -= cash
        return f"you successfully have topped up {phone_number}"

    def remove_card(self) -> str:
        if self.inserted_card is None:
            return "Card is not inserted"

        self.inserted_card = None
        return "your card was removed"