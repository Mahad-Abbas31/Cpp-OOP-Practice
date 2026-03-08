// Fig. 9.5: SalesPerson.h
// SalesPerson class definition.
// Member functions defined in SalesPerson.cpp.
#ifndef SALESPERSON_H
#define SALESPERSON_H

class SalesPerson{
public:
    static const int monthsPerYear = 12; // months in one year
    SalesPerson(); // constructor
    
    void getSalesFromUser(); // input sales from keyboard
    void setSales( int, double ); // set sales for a specific month
    void printAnnualSales(); // summarize and print sales

    // ___ Modifications
    void writeToFile();                 // store record in file
    static void findHighestSales();     // find highest sales employee

private:
    double sales[ monthsPerYear ];
    int employeeID;

    double totalAnnualSales();
};

#endif