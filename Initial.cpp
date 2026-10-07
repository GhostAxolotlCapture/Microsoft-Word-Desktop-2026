#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product {
    string name;
    int quantity;
    double price;
};

class Warehouse {
private:
    vector<Product> products;

public:
    void addProduct(const string& name, int quantity, double price) {
        products.push_back({name, quantity, price});
    }

    double totalValue() const {
        double total = 0;

        for (const auto& product : products) {
            total += product.quantity * product.price;
        }

        return total;
    }

    void sortByValue() {
        sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
            return a.quantity * a.price > b.quantity * b.price;
        });
    }

    void showReport() const {
        cout << "Warehouse Report\n";
        cout << "================\n";
        cout << fixed << setprecision(2);

        for (const auto& product : products) {
            double value = product.quantity * product.price;

            cout << product.name
                 << " | Quantity: " << product.quantity
                 << " | Price: $" << product.price
                 << " | Value: $" << value << '\n';
        }

        cout << "\nTotal inventory value: $" << totalValue() << '\n';
    }
};

int main() {
    Warehouse warehouse;

    warehouse.addProduct("Laptop", 12, 899.99);
    warehouse.addProduct("Keyboard", 35, 79.50);
    warehouse.addProduct("Monitor", 18, 249.99);
    warehouse.addProduct("Mouse", 50, 39.90);
    warehouse.addProduct("Headset", 24, 129.99);

    warehouse.sortByValue();
    warehouse.showReport();

    return 0;
}