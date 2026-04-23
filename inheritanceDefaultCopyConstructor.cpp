/*
--> Copy Constructor in Inheritance
    - Compiler generates copy constructor for base and
    derived classes, if needed (Shallow copy)
    - Derived class Copy constructor is invoked which in turn
    calls the Copy constructor of the base class
    - The base part is copied first and then the derived part    
*/

// ____ PROBLEM (SHALLOW COPY OF *POINTERS)
#include <iostream>
using namespace std;

class Parent{
    int *ptr;
  public:
    // ____ Constructor
    Parent(int p){
        ptr = new int;
        *ptr = p;
    }

    // ____ Getter
    int getPtr(){       return *ptr;       }

    void setptr(int p){     *ptr = p;      }
};

class Child : public Parent{
    int *ptr2;
  public:
    // ____ Constructor
    Child(int p, int q):Parent(p){
        ptr2 = new int;
        *ptr2 = q;
    }

    // ____ Getter
    int getPtr2(){      return *ptr2;       }

    void setptr2(int q){     *ptr2 = q;      }

};

int main(){
    Child c1(10, 20);
    cout << "Child c1: " << c1.getPtr() << ", " << c1.getPtr2() << endl;
    
    Child c2 = c1;
    cout << "Child c2: " << c2.getPtr() << ", " << c2.getPtr2() << endl;
    
    // ____ This changed the 20 to 99 in both objects due to same address of pointers (shallow copy)
    c2.setptr2(99);
    cout << "Child c1: " << c1.getPtr() << ", " << c1.getPtr2() << endl;
    cout << "Child c2: " << c2.getPtr() << ", " << c2.getPtr2() << endl;

}