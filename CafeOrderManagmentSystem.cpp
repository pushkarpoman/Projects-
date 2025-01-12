#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

class MenuItem {
public:
    MenuItem(const std::string& name, double price) : name(name), price(price) {}

    const std::string& getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

private:
    std::string name;
    double price;
};

class Order {
public:
    void addItem(const MenuItem& item, int quantity) {
        items.push_back({ item, quantity });
    }

    double calculateTotalCost() const {
        double totalCost = 0.0;
        for (const auto& item : items) {
            totalCost += item.first.getPrice() * item.second;
        }
        return totalCost;
    }

    void displayOrder() const {
        std::cout << "===== Order Details =====\n";
        for (const auto& item : items) {
            std::cout << item.first.getName() << " x " << item.second << " = $"
                      << std::fixed << std::setprecision(2) << item.first.getPrice() * item.second << "\n";
        }

        std::cout << "--------------------------\n";
        std::cout << "Total Cost: $" << std::fixed << std::setprecision(2) << calculateTotalCost() << "\n";
    }

private:
    std::vector<std::pair<MenuItem, int>> items;
};

class Cafeteria {
public:
    void addMenuItem(const MenuItem& item) {
        menu.push_back(item);
    }

    void displayMenu() const {
        std::cout << "===== Menu =====\n";
        for (const auto& item : menu) {
            std::cout << item.getName() << " | Price: $" << std::fixed << std::setprecision(2) << item.getPrice() << "\n";
        }
    }

    bool placeOrder(Order& order) {
        std::string itemName;
        int quantity;

        std::cout << "Enter item name to add to the order (type 'done' to finish): ";
        std::cin >> itemName;

        while (itemName != "done") {
            auto it = std::find_if(menu.begin(), menu.end(),
                                   [itemName](const MenuItem& m) { return m.getName() == itemName; });

            if (it != menu.end()) {
                std::cout << "Enter quantity: ";
                std::cin >> quantity;

                order.addItem(*it, quantity);
            } else {
                std::cout << "Item not found in the menu.\n";
            }

            std::cout << "Enter another item name or 'done' to finish: ";
            std::cin >> itemName;
        }

        return !order.calculateTotalCost();  // Returns false if the order is empty
    }

private:
    std::vector<MenuItem> menu;
};

int main() {
    // Sample Menu Items
    MenuItem coffee("Coffee", 2.5);
    MenuItem sandwich("Sandwich", 5.0);
    MenuItem salad("Salad", 3.75);
    MenuItem Burger("Burger", 6.50);
    MenuItem Pizza("Pizza", 7.0);

    // Create Cafeteria
    Cafeteria cafeteria;
    cafeteria.addMenuItem(coffee);
    cafeteria.addMenuItem(sandwich);
    cafeteria.addMenuItem(salad);
    cafeteria.addMenuItem(Burger);
    cafeteria.addMenuItem(Pizza);

    // Display Menu
    cafeteria.displayMenu();

    // Place Order
    Order customerOrder;
    if (!cafeteria.placeOrder(customerOrder)) {
        std::cout << "Order is placed \n";
        return 0;
    }

    // Display Order
    customerOrder.displayOrder();

    return 0;
}

			
