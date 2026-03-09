#include <iostream>
#include "Time.h"

using namespace std;

int main(){
    Time t;

    if(!t.setHour(25))
        cout << "Error: Invalid hour value\n";

    if(!t.setMinute(70))
        cout << "Error: Invalid minute value\n";

    if(!t.setSecond(45))
        cout << "Second set successfully\n";

    cout << "\nCurrent Time (Universal): ";
    t.printUniversal();

    cout << "\nCurrent Time (Standard): ";
    t.printStandard();

    cout << endl;

    return 0;
}