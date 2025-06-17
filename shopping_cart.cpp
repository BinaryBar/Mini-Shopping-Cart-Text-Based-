#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Item {
    string name;
    float price;
    int quantity;
};

class Cart {
private:
    vector<Item> items;

public:
    void addItem(const string& name, float price, int quantity) {
        Item item = {name, price, quantity};
        items.push_back(item);
        cout << "✅ " << name << " added to cart.\n";
    }

    void viewCart() {
        if (items.empty()) {
            cout << "🛒 Your cart is empty!\n";
            return;
        }

        float total = 0;
        cout << "\n🧾 Cart Summary:\n";
        cout << left << setw(15) << "Item"
             << setw(10) << "Price"
             << setw(10) << "Qty"
             << setw(10) << "Total" << endl;
        cout << "--------------------------------------\n";

        for (const auto& item : items) {
            float itemTotal = item.price * item.quantity;
            cout << setw(15) << item.name
                 << setw(10) << fixed << setprecision(2) << item.price
                 << setw(10) << item.quantity
                 << setw(10) << itemTotal << endl;
            total += itemTotal;
        }

        cout << "--------------------------------------\n";
        cout << "🧾 Total Amount: $" << total << "\n\n";
    }
};

int main() {
    Cart cart;
    int choice;

    while (true) {
        cout << "\n🛒 Shopping Cart Menu\n";
        cout << "1. Add Item\n";
        cout << "2. View Cart\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            float price;
            int quantity;
            cout << "Enter item name: ";
            cin.ignore(); // Clear buffer
            getline(cin, name);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter quantity: ";
            cin >> quantity;
            cart.addItem(name, price, quantity);
        } else if (choice == 2) {
            cart.viewCart();
        } else if (choice == 3) {
            cout << "👋 Thank you for shopping!\n";
            break;
        } else {
            cout << "❌ Invalid choice. Try again.\n";
        }
    }

    return 0;
}
