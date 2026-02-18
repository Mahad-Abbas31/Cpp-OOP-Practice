#include<iostream>

using namespace std;

/*
--> COPY CONSTRUCTOR
        "A copy constructor is a special constructor
        in C++ that is used to create a new object as 
        a copy of an existing object of the same class."

 -> WHY USED?
     - C++ provides a default copy constructor, but it performs a shallow copy.
     - If your class uses pointers or dynamic memory, you need a user-defined copy constructor 
       to perform a deep copy.
    
*/

class Hero{
    string name;
    string power;
    string region;
    int level;
    int stars;
    
public:
    //__ Using "this" to resolve naming conflict
    Hero(string n, string p, string r, int l, int s){
        name = n;
        power = p;
        region = r;
        level = l;
        stars = s;
    }

    //__ Display function
    void display(){
        cout << endl << name << endl;
        cout << power << endl;
        cout << region << endl;
        cout << level << endl;
        cout << stars << endl;
    }
};

class Student{
    string name;
    int age;
    int *ptr;
    
public:
    //___ Copy Constructor Method/Function
    Student(const Student &orgObj){               //--> Pass by Reference
        cout << "\nI am Custom Copy Constructor\n";
        name = orgObj.name;
        age = orgObj.age;
        ptr = new int;
        *ptr = *(orgObj.ptr);
        *ptr = 100;
        cout << "I am Deep Copy\n";
    }

    // ___ Shallow Copy 
    // Student(Student &orgObj){               //--> Pass by Reference
    //     cout << "I am Custom Copy Constructor\n";
    //     name = orgObj.name;
    //     age = orgObj.age;
    //     ptr = orgObj.ptr;
    // }

    Student(string n, int a, int p){
        name = n;
        age = a;
        ptr = new int;
        *ptr = p;
    }

    //__ Display function
    void display(){
        cout << endl << name << endl;
        cout << age << endl;
        cout << *ptr << endl;
    }

    // ___ Destructer
    ~Student(){
        delete ptr;
    }
};

// ___ Main
int main(){

    Hero ironman("Ironman", "Intelligence", "America", 50, 7);
    ironman.display();

/*
    1. Default Copy Constructor made by the Compiler will be called if
       there is no Custom Copy Constructor created by the programmer.
    2. If a Copy Constructor is created by the programmer, it will be
       called instead of Default Copy Constructor. 
*/
    Hero warMachine=ironman;
    warMachine.display();

    // Hero cap(ironman);
    // cap.display();

    Student s1("Mahad", 61, 76);
    s1.display();
    
    Student s2=s1;
    s1.display();
    s2.display();

    return 0;
}

/*         SHALLOW COPY (Deafualt)              *              DEEP COPY (Custom)              
                                                *
    -> This runs on its own on the backend by   *     -> Customly made when we have to copy pointers
    the compiler if we have not created any     *        also. Using (new) keyword.
    any copy constructor.                       *
                                                *
    -> Shallow copy can work for many variables *     -> Allows pointers to allocate new memory and
    but when we are copying pointers, we        *        to copy actual value of the variable of 
    have to make a custom copy constructor      *        pointers. It's good practice, safe and correct
    because both pointers copy at the same      *        method while working with pointers.
    address so many problems are faced.         *
                                                *
    -> Hero warMachine=ironman;                 *     -> Student s2=s1;
    (No Custom Copy Constructor Defined)        *
                                                *
*/