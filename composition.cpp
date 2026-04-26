/*
--> Composition
    "Composition is a strong “has-a” relationship where
    One class owns another class, and the lifetime of the
    contained object depends on the owner."

✔ An object can be owned by several other aggregating objects. 
✔ If an object is exclusively owned by an aggregating object, the relationship between the
   object and its aggregating object is referred to as a composition.
✔ Composition is actually a special case of the aggregation relationship.
✔ If the parent object is destroyed → child object is also destroyed

 -> Real-life examples:
    ✔ A House has Rooms
    ✔ A Car has an Engine
    ✔ A Human has a Heart
    👉 If the house is destroyed → rooms don’t exist independently.

 -> Engine is part of Car
    ✔ It is created automatically inside Car
    ✔ It is destroyed automatically when Car is destroyed
    👉 This proves ownership + dependent lifetime

 -> Composition is usually implemented using:
    ✔ Objects as data members (not pointers)

 -> Key Characteristics
    ✔ Strong relationship
    ✔ Full ownership
    ✔ Same lifecycle
    ✔ Usually no pointers involved
    ✔ Composition is a stronger relationship, because Composed object becomes a part of the composer 
    ✔ Composed object can’t exist independently
    ✔ Composition is shown with a filled diamond (◆)

 -> Implementation
    1. Constructors of the sub-objects are always executed before the constructors of the master class

*/
#include<iostream>
using namespace std;

class Name{
  public:
    string fName;
    string lName;
    Name(string f = "Unknown", string l = "") {
        fName = f;
        lName = l;
    }

    void display() {
        cout << fName << " " << lName;
    }
};

class Hands{
  public:
    Hands(){     cout << "We are hands of this person\n";      }
};

class Feet{
  public:
    Feet(){      cout << "We are feet of this person\n";       }
};

class Head{
  public:
    Head(){       cout << "I am head of this person\n";        }
};

class Human{
  public:    
    Name name;
    int age;
    string gender;
    Hands h;
    Feet f;
    Head p;

    Human(string f="Unknown", string l="", int a=0, string g="Unknown") : name(f, l), age(a), gender(g)   // ✅ initializer list
    {
        cout << "I am ";
        name.display();
        cout << endl;
    }
};


int main(){
    Human h1("Ali", "Hamza", 21, "male");
    cout << endl << h1.name.fName << endl;
    cout << endl << h1.name.lName << endl;
}