#include <iostream>
#include "Date.h"

using namespace std;

int main(){

    Date d1;                 // default date
    Date d2(10,5,2024);      // parameterized date

    // ___ Set date
    d1.setDay(15);
    d1.setMonth(3);
    d1.setYear(2025);

    cout << "Date d1: "
         << d1.getDay() << "/"
         << d1.getMonth() << "/"
         << d1.getYear() << endl;


    // ___ Add days
    d1.addDay(20);

    cout << "After adding days: "
         << d1.getDay() << "/"
         << d1.getMonth() << "/"
         << d1.getYear() << endl;


    // ___ Add months
    d1.addMonth(10);

    cout << "After adding months: "
         << d1.getDay() << "/"
         << d1.getMonth() << "/"
         << d1.getYear() << endl;


    // ___ Add years
    d1.addYear(2);

    cout << "After adding years: "
         << d1.getDay() << "/"
         << d1.getMonth() << "/"
         << d1.getYear() << endl;


    // ___ Second object
    cout << "\nDate d2: "
         << d2.getDay() << "/"
         << d2.getMonth() << "/"
         << d2.getYear() << endl;


    // ___ Set Exam Date (static)
    Date::setExamDate(7,6,2026);

    cout << "\nExam date set successfully" << endl;

    return 0;
}