#include <iostream>
#include "SalesPerson.h"

using namespace std;

int main(){

    int choice;

    do{
        cout << "\n1. Add Sales Record";
        cout << "\n2. Show Employee with Highest Sales";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1){
            SalesPerson s;

            s.getSalesFromUser();
            s.printAnnualSales();
            s.writeToFile();
        }
        else if(choice == 2)
            SalesPerson::findHighestSales();
    
    }while(choice != 3);

    return 0;
}