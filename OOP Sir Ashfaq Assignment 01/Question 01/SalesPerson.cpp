#include <iostream>
#include <fstream>
#include <iomanip>
#include "SalesPerson.h"

using namespace std;

// ___ Constructor
SalesPerson::SalesPerson(){
    for(int i=0; i<monthsPerYear; ++i )
        sales[ i ] = 0.0;
}


// ___ Salaries User Input
void SalesPerson::getSalesFromUser(){

    cout << "Enter Employee ID: ";
    cin >> employeeID;

    double salesFigure;
    for (int i=1; i<=monthsPerYear; ++i){
        cout << "Enter sales amount for month " << i << ": ";
        cin >> salesFigure;
        setSales( i, salesFigure );
    }
}

// ___ Monthly Salary Array Formation
void SalesPerson::setSales(int month, double amount){
    if (month >= 1 && month <= monthsPerYear && amount > 0 )
        sales[ month - 1 ] = amount;
    else
        cout << "Invalid month or sales figure" << endl;
}

// ___ Display Annual Sales
void SalesPerson::printAnnualSales(){

    cout << fixed << setprecision(2);
    cout << "\nEmployee ID: " << employeeID;
    cout << "\nTotal Annual Sales: $" << totalAnnualSales() << endl;
}

// ___ Annual Sales Calculate
double SalesPerson::totalAnnualSales(){
    double total = 0.0;

    for ( int i = 0; i < monthsPerYear; ++i )
        total += sales[ i ];
    
    return total;
}


void SalesPerson::writeToFile(){
    ofstream fout("sales.txt", ios::app);

    fout << employeeID << " ";

    for(int i = 0; i < monthsPerYear; i++)
        fout << sales[i] << " ";

    fout << totalAnnualSales() << endl;
    fout.close();
}

void SalesPerson::findHighestSales(){

    ifstream fin("sales.txt");

    int id, maxID;
    double sale, total, maxTotal = -1;

    while(fin >> id){

        total = 0;

        for(int i = 0; i < monthsPerYear; i++){
            fin >> sale;
            total += sale;
        }

        fin >> sale; // stored total

        if(total > maxTotal){
            maxTotal = total;
            maxID = id;
        }
    }

    fin.close();

    if(maxTotal >= 0){
        cout << "\nEmployee with Highest Sales\n";
        cout << "Employee ID: " << maxID << endl;
        cout << "Total Sales: $" << fixed << setprecision(2) << maxTotal << endl;
    }
    else
        cout << "No records found.\n";
}