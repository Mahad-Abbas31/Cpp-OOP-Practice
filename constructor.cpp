#include <iostream>

using namespace std;
/*
--> CONSTRUCTOR:
    A constructor in OOP is a special member
    function of a class that is automatically called
    when an object of the class is created.

 -> CHARACTERISTICS OF CONSTRUCTOR:
    - It has the same name as the class.
    - It has no return type (not even void).
    - It is called automatically when an object is created.
    - It is usually declared as public.
    - It is used for initialization, not for computation.
    - Memory allocation occurs when Constructor is called.

 -> TYPES OF CONSTRUCTOR:
    - Non-parameterized constructors.
    - Parameterized constructors.
    - Copy constructors. (used to copy one object to another)

 -> CONSTRUCTOR OVERLOADING:
      "The phenomenon in which a class has two or more constructors of different or same types."
    -  Its is an example of Polymorphism.

*/
class Hero{
    string name;
    string power;
    string region;
    int level;
    int stars;
    
public:
    // - Non-parameterized constructors.
    Hero(){
        cout << "I am an Avenger!";
    }
    
    // - Parameterized constructors.
    Hero(string n, string p, string r, int l, int s){
        name = n;
        power = p;
        region = r;
        level = l;
        stars = s;
    }

    // - Copy constructors.

    //___ Dispaly Function
    void display(){
        cout << name << endl;
        cout << power << endl;
        cout << region << endl;
        cout << level << endl;
        cout << stars << endl;
    }
};

int main(){
    // - Non-parameterized constructors.
    // Hero h;

    // - Parameterized constructors.
    Hero ironman("Ironman", "Brain", "America", 50, 7);
    ironman.display();

}