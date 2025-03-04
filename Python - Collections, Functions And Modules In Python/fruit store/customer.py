from fruit_manager import FruitManager
import datetime

class Customer:
    def __init__(self):
        self.cart = {}
        self.fruit_manager = FruitManager()

    def add_to_cart(self, fruit_name, quantity):
        if fruit_name in self.fruit_manager.fruit_stock and self.fruit_manager.fruit_stock[fruit_name] >= quantity:
            self.cart[fruit_name] = self.cart.get(fruit_name, 0) + quantity
            print(f"Added {quantity} {fruit_name}(s) to your cart.")
        else:
            print("Not enough stock available.")

    def checkout(self):
        if not self.cart:
            print("Cart is empty.")
            return

        with open("transaction_log.txt", "a") as log_file:
            log_file.write(f"\nTransaction on {datetime.datetime.now()}:\n")
            for fruit, quantity in self.cart.items():
                self.fruit_manager.fruit_stock[fruit] -= quantity
                log_file.write(f"Purchased {quantity} {fruit}(s)\n")
            self.fruit_manager.save_stock()
        
        print("Purchase successful! Cart has been cleared.")
        self.cart.clear()
