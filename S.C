#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to store product information
struct Product {
    int id;
    string name;
    double price;
    int quantity;
    string date;
};

// Global variables
const int MAX_PRODUCTS = 100;
Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function prototypes
void addProduct();
void updateProduct();
void deleteProduct();
void viewProducts();
void saveToFile();
void loadFromFile();

int main() {
    int choice;
    loadFromFile();

    do {
        cout << "\n*** Inventory Management System ***\n";
        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Delete Product\n";
        cout << "4. View Products\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: updateProduct(); break;
            case 3: deleteProduct(); break;
            case 4: viewProducts(); break;
            case 5: saveToFile(); cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a product
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Inventory is full.\n";
        return;
    }

    Product p;
    cout << "Enter Product ID: ";
    cin >> p.id;
    cout << "Enter Product Name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter Product Price: ";
    cin >> p.price;
    cout << "Enter Quantity: ";
    cin >> p.quantity;
    cout << "Enter Date (DD-MM-YYYY): ";
    cin.ignore();
    getline(cin, p.date);

    inventory[productCount++] = p;
    cout << "Product added successfully!\n";
}

// Function to update a product
void updateProduct() {
    int id;
    cout << "Enter Product ID to update: ";
    cin >> id;

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            cout << "Enter new Product Name: ";
            cin.ignore();
            getline(cin, inventory[i].name);
            cout << "Enter new Product Price: ";
            cin >> inventory[i].price;
            cout << "Enter new Quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter new Date (DD-MM-YYYY): ";
            cin.ignore();
            getline(cin, inventory[i].date);

            cout << "Product updated successfully!\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

// Function to delete a product
void deleteProduct() {
    int id;
    cout << "Enter Product ID to delete: ";
    cin >> id;

    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            cout << "Product deleted successfully!\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

// Function to view all products
void viewProducts() {
    if (productCount == 0) {
        cout << "No products in inventory.\n";
        return;
    }

    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" 
         << setw(10) << "Qty" << setw(15) << "Date\n";
    cout << "----------------------------------------------------------\n";
    for (int i = 0; i < productCount; i++) {
        cout << left << setw(10) << inventory[i].id
             << setw(20) << inventory[i].name
             << setw(10) << inventory[i].price
             << setw(10) << inventory[i].quantity
             << setw(15) << inventory[i].date << endl;
    }
}

// Function to save inventory to file
void saveToFile() {
    ofstream file("inventory.txt");
    if (file.is_open()) {
        file << productCount << endl;
        for (int i = 0; i < productCount; i++) {
            file << inventory[i].id << endl
                 << inventory[i].name << endl
                 << inventory[i].price << endl
                 << inventory[i].quantity << endl
                 << inventory[i].date << endl;
        }
        file.close();
        cout << "Data saved successfully!\n";
    } else {
        cout << "Error saving data to file.\n";
    }
}

// Function to load inventory from file
void loadFromFile() {
    ifstream file("inventory.txt");
    if (file.is_open()) {
        file >> productCount;
        file.ignore();
        for (int i = 0; i < productCount; i++) {
            file >> inventory[i].id;
            file.ignore();
            getline(file, inventory[i].name);
            file >> inventory[i].price;
            file >> inventory[i].quantity;
            file.ignore();
            getline(file, inventory[i].date);
        }
        file.close();
        cout << "Data loaded successfully!\n";
    } else {
        cout << "No previous data found.\n";
    }
}
