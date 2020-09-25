#include<iostream>
using namespace std;

class Item {
private:
    string name;
    double price;
    int quantity;

public:
    Item(string name, double price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    string toString() {
        return "Name: " + name + " " + "Price: " + to_string(price) + " " + "Quantity: " + to_string(quantity);
    }
};

