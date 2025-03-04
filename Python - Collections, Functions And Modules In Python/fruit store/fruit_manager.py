import json
import os

class FruitManager:
    def __init__(self):
        self.fruit_stock = {}
        self.load_stock()

    def load_stock(self):
        if os.path.exists("fruit_stock.json"):
            with open("fruit_stock.json", "r") as file:
                self.fruit_stock = json.load(file)
        else:
            self.fruit_stock = {}

    def save_stock(self):
        with open("fruit_stock.json", "w") as file:
            json.dump(self.fruit_stock, file, indent=4)

    def add_fruit(self, fruit_name, quantity):
        self.fruit_stock[fruit_name] = self.fruit_stock.get(fruit_name, 0) + quantity
        self.save_stock()
        print(f"Added {quantity} {fruit_name}(s) to stock.")

    def view_stock(self):
        if not self.fruit_stock:
            print("No stock available.")
        else:
            for fruit, quantity in self.fruit_stock.items():
                print(f"{fruit}: {quantity}")

    def update_stock(self, fruit_name, quantity):
        if fruit_name in self.fruit_stock:
            self.fruit_stock[fruit_name] = quantity
            self.save_stock()
            print(f"Updated {fruit_name} stock to {quantity}.")
        else:
            print("Fruit not found in stock.")