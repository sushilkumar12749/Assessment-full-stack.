from fruit_manager import FruitManager
from customer import Customer

def main():
    fruit_manager = FruitManager()
    customer = Customer()
    
    while True:
        print("\n=== Fruit Store Menu ===")
        print("1. Add Fruit Stock")
        print("2. View Stock")
        print("3. Update Fruit Stock")
        print("4. Add to Cart")
        print("5. Checkout")
        print("6. Exit")
        choice = input("Enter your choice: ")
        
        if choice == "1":
            fruit = input("Enter fruit name: ")
            quantity = int(input("Enter quantity: "))
            fruit_manager.add_fruit(fruit, quantity)
        elif choice == "2":
            fruit_manager.view_stock()
        elif choice == "3":
            fruit = input("Enter fruit name: ")
            quantity = int(input("Enter new quantity: "))
            fruit_manager.update_stock(fruit, quantity)
        elif choice == "4":
            fruit = input("Enter fruit name: ")
            quantity = int(input("Enter quantity: "))
            customer.add_to_cart(fruit, quantity)
        elif choice == "5":
            customer.checkout()
        elif choice == "6":
            print("Exiting the application...")
            break
        else:
            print("Invalid choice, please try again.")

if __name__ == "__main__":
    main()
