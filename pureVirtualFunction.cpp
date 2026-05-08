/*
--> Pure Virtual Function
    "A pure virtual function is a virtual function in the base class 
    that has no implementation and must be overridden in the derived class."
    - It is used to achieve abstraction.

-> Abstract Class:  
    - A class containing at least one pure virtual function
    - ❌ You cannot create objects of an abstract class.
    - We can have pointers and references of abstract class

-> Why Use Pure Virtual Functions?
    - To force derived classes to provide implementation
    - To achieve abstraction
    - To define a common interface
    - To enforce function overriding and achieve abstraction.

-> Important Exam Point
    - If a derived class does NOT override all pure virtual functions:
         That derived class also becomes abstract.
*/

#include<iostream>
using namespace std;

// ___ Abstract Class
class Employee{
protected:
    string name;

public:
    Employee(string n) : name(n){}

    // ___ Pure Virtual Function
    virtual void calculateSalary() = 0;
    void status(){
        cout << "I am an Abstract class\n";
    }
};

// ____ Derived Class: Doctor
class Doctor : public Employee{
    int patients;

public:
    Doctor(string n, int p) : Employee(n), patients(p){}

    // ____ Overriding
    void calculateSalary(){
        cout << "Doctor " << name
             << " Salary: " << patients * 500 << endl;
    }
};

// ____ Derived Class: Nurse
class Nurse : public Employee{
    int hours;

public:
    Nurse(string n, int h) : Employee(n), hours(h){}

    // ____ Overriding
    void calculateSalary(){
        cout << "Nurse " << name
             << " Salary: " << hours * 100 << endl;
    }
};

// ____ Derived Class: Receptionist
class Receptionist : public Employee{
    int days;

public:
    Receptionist(string n, int d) : Employee(n), days(d){}

    // ____ Overriding
    void calculateSalary(){
        cout << "Receptionist " << name
             << " Salary: " << days * 200 << endl;
    }
};

int main(){

    Doctor d("Ali", 10);
    Nurse n("Sara", 40);
    Receptionist r("Ahmed", 25);
    Employee *e;
    d.calculateSalary();
    n.calculateSalary();
    r.calculateSalary();

    e->status();

    return 0;
}