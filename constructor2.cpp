/*
Design an Inventory class that can hold information and calculate
data for items in a retail store’s inventory. The class should have
the following private member variables
*/
#include <iostream>
using namespace std;

class Inventory {
private:
    int itemNumber;   
    int quantity;     
    double cost;      
    double totalCost; 

public:
    Inventory() {
        itemNumber = 0;
        quantity = 0;
        cost = 0.0;
        totalCost = 0.0;
    }

    Inventory(int i, int q, double c) {
        itemNumber = i;
        quantity = q;
        cost = c;
        setTotalCost();  
    }

    void setItemNumber(int i) {
        itemNumber = i;
    }

    void setQuantity(int q) {
        quantity = q;
        setTotalCost(); 
    }

    void setCost(double c) {
        cost = c;
        setTotalCost(); 
    }

    void setTotalCost() {
        totalCost = quantity * cost;
    }

    int getItemNumber() {
        return itemNumber;
    }

    int getQuantity() {
        return quantity;
    }

    double getCost() {
        return cost;
    }

    double getTotalCost() {
        return totalCost;
    }
};

void PrintData(Inventory item) {
    cout << "\n===== Inventory Details =====\n";
    cout << "Item Number: " << item.getItemNumber() << endl;
    cout << "Quantity: " << item.getQuantity() << endl;
    cout << "Cost per Item: " << item.getCost() << endl;
    cout << "Total Inventory Cost: " << item.getTotalCost() << endl;
}

int main() {
    Inventory item1;
    PrintData(item1);

    int itemNo, qty;
    double price;

    cout << "\nEnter Item Number: ";
    cin >> itemNo;
    cout << "Enter Quantity: ";
    cin >> qty;
    cout << "Enter Cost per Item: ";
    cin >> price;

    Inventory item2(itemNo, qty, price);
    PrintData(item2);

    return 0;
}