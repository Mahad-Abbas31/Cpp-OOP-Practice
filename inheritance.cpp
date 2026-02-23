#include<iostream>

using namespace std;

/*
--> INHERITANCE
        "Inheritance is an OOP concept where one class 
        (child/derived class) acquires the properties 
        and behaviors of another class (parent/base class)."

 -> WHY USED?
     - ✅ Code reusability
     - ✅ Extensibility
     - ✅ Hierarchical classification

 -> NOTE:
     - First, construtor of Parent class is called, then the constructor of Child class is called.   
     - First, destructor of Child class is called, then the constructor of Parent class is called.   
     - When Parent Class has a defined constructor, it must be placed after the Child Class Constructors
      after the symbol ":".  

*/

// ___ Parent Class
class Person{
public:
    string name;
    string region;          
    int age;

    Person(string name, string region, int age){
        this->age = age;
        this->name = name;
        this->region = region;
    }
};

// ___ Child Classes
class Hero : public Person{
    string power;
    int level;
    int stars;
    
public:
    // ___ Parameterized Constructor
    Hero(string name, string power, string region, int level, int stars, int age) : Person( name, region, age){
        this->name = name;
        this->age = age;
        this->region = region;
        this->power = power;
        this->level = level;
        this->stars = stars;
    }

    //__ Display function
    void display(){
        cout << endl << name << endl;
        cout << age << endl;
        cout << power << endl;
        cout << region << endl;
        cout << level << endl;
        cout << stars << endl;
    }
};

class Student : public Person{
    int *ptr;
    
public:
    //___ Copy Constructor Method/Function
    Student(const Student &orgObj) : Person(name, region, age){               //--> Pass by Reference
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

    Student(string name, int age, int p) : Person(name, region, age){
        this->name = name;
        this->age = age;
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

    Hero ironman("Ironman", "Intelligence", "America", 50, 7, 35);
    ironman.display();

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
