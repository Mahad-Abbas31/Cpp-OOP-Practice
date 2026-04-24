/*
--> Assignment in Inheritance
    - Compiler generates assignment operator for base and
    derived classes, if needed (Shallow copy)
    - Derived class assignment operator is invoked which in turn
    calls the assignment operator of the base class
    - The base part is assigned first and then the derived part    
*/

// ____ Solution (SHALLOW COPY OF *POINTERS)
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

    // ____ Copy Constructor
    Parent(const Parent& p){
        ptr = new int;
        *ptr = *p.ptr;
    }

    // ____ Getter
    int getPtr(){       return *ptr;       }
    
    // ____ Setter
    void setptr(int p){     *ptr = p;      }

    // ____ Assignment Operator
    Parent &operator=(const Parent &p){
        ptr = new int;
        *ptr = *p.ptr;
    }
};

// ____ Case 1
class Child : public Parent{
    int *ptr2;
  public:
    // ____ Constructor
    Child(int p, int q):Parent(p){
        ptr2 = new int;
        *ptr2 = q;
    }

    // ____ NO Copy Constructor for this derived class
    /* - Compiler generates copy constructor for derived class
       - Calls the copy constructor of the base class (deep copy)
       - Then performs the shallow copy of the derived class’s data members
    */

    // ____ Getter
    int getPtr2(){      return *ptr2;       }
    
    // ____ Setter
    void setptr2(int q){     *ptr2 = q;      }
};

// ____ Case 2
class Child1 : public Parent{
    int *ptr2;
  public:
    // ____ Constructor
    Child1(int p, int q):Parent(p){
        ptr2 = new int;
        *ptr2 = q;
    }

    // ____ Copy Constructor in both base and derived class
    /* - Compiler generates copy constructor for derived class
       - Calls the copy constructor of the base class (deep copy)
       - Then performs the shallow copy of the derived class’s data members
    */

    // -> Programmer must explicitly call the base class copy constructor from the copy constructor of derived class (above line)
    Child1(const Child1& c):Parent(c){     /*  <-- Look Closely   */  
        ptr2 = new int;
        *ptr2 = *c.ptr2;
    }

    // ____ Assignment Operator
    Child1 &operator=(const Child1 &c){
        // -> Programmer has to call assignment operator of base class, if he is writing assignment operator of derived class
        Parent::operator=(c);     /*  <--- Look Closely  */
        ptr2 = new int;
        *ptr2 = *c.ptr2;
    }

    // ____ Getter
    int getPtr2(){      return *ptr2;       }
    
    // ____ Setter
    void setptr2(int q){     *ptr2 = q;      }
};

int main(){
    cout << "-----------Without Derived Class Copy Constructor---------" << endl;
    Child c1(10, 20);
    cout << "Child c1: " << c1.getPtr() << ", " << c1.getPtr2() << endl;
    
    Child c2 = c1;
    cout << "Child c2: " << c2.getPtr() << ", " << c2.getPtr2() << endl;
    
    // ____ This changed the 20 to 99 in both objects due to same address of pointers (shallow copy)
    // ____ This changed the 10 to 77 in only c2 due to defined copy constructor of parent class(deep copy)
    c2.setptr(77);
    c2.setptr2(99);
    cout << "Child c1: " << c1.getPtr() << ", " << c1.getPtr2() << endl;
    cout << "Child c2: " << c2.getPtr() << ", " << c2.getPtr2() << endl;

    
    cout << "\n-----------With Derived Class Copy Constructor---------" << endl;
    Child1 c3(10, 20);
    cout << "Child c1: " << c3.getPtr() << ", " << c3.getPtr2() << endl;
    
    Child1 c4 = c3;
    cout << "Child c2: " << c4.getPtr() << ", " << c4.getPtr2() << endl;
    
    // ____ This changed the 10 to 77 in only c4 due to defined copy constructor of parent class(deep copy)
    // ____ This changed the 20 to 99 in only c4 due to defined copy constructor of derived class(deep copy)
    c4.setptr(77);
    c4.setptr2(99);
    cout << "Child c3: " << c3.getPtr() << ", " << c3.getPtr2() << endl;
    cout << "Child c4: " << c4.getPtr() << ", " << c4.getPtr2() << endl;
    
    c3 = c4;
    cout << "\n-----------After Assigning c3 = c4---------" << endl;
    cout << "Child c3: " << c3.getPtr() << ", " << c3.getPtr2() << endl;
    cout << "Child c4: " << c4.getPtr() << ", " << c4.getPtr2() << endl;

    return 0;
}