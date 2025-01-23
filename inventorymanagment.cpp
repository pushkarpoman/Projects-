#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a product
struct Product {
    string name;
    double price;
    int quantity;
};

// Function to add a new product to the inventory
void addProduct(vector<Product>& inventory) {
    Product newProduct;
    cout << "Enter product name: ";
    cin.ignore(); // Ignore the newline character left by cin
    getline(cin, newProduct.name);
    cout << "Enter product price: ";
    cin >> newProduct.price;
    cout << "Enter product quantity: ";
    cin >> newProduct.quantity;

    inventory.push_back(newProduct);
    cout << "Product added successfully!" << endl;
}

// Function to display all products in the inventory
void displayInventory(const vector<Product>& inventory) {
    cout << "\nInventory:" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Name\t\tPrice\t\tQuantity" << endl;
    for (const auto& product : inventory) {
        cout << product.name << "\t\t$" << product.price << "\t\t" << product.quantity << endl;
    }
    cout << "-----------------------------------" << endl;
}

int main() {
    vector<Product> inventory;

    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Display Inventory\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                displayInventory(inventory);
                break;
            case 3:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
