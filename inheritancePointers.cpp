// ____ Parent Class Pointer containing the address of Child Class

#include<iostream>
using namespace std;

class Parent {
    public:
    Parent(){
        cout << "Parent\n";
    }
    void Hello() { cout << "Hi from a Parent!\n"; }
};

class Child : public Parent {
    public:
    Child():Parent(){
        cout << "Child\n";
    }
    void Hello() { cout << "Hi from a Child!\n"; }
};

int main() {

    Parent* P;
    Child C;
    P = &C;
    P->Hello();
    C.Hello();

    return 0;
}