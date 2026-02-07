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
    //___ Copy Constructor Method/Function
    Hero(Hero &orgObj){               //--> Pass by Reference
        cout << "I am Custom Copy Constructor\n";
        this->name = orgObj.name;
        this->power = orgObj.power;
        this->region = orgObj.region;
        this->level = orgObj.level;
        this->stars = orgObj.stars;
    }

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
        cout << name << endl;
        cout << power << endl;
        cout << region << endl;
        cout << level << endl;
        cout << stars << endl;
    }


};


int main(){

    Hero ironman("Ironman", "Intelligence", "America", 50, 7);
    ironman.display();

/*
    1. Default Copy Constructor made by the Compiler will be called if
       there is no Custom Copy Constructor created by the programmer.
    2. If a Copy Constructor is created by the programmer, it will be
       called instead of Default Copy Constructor. 
*/
    Hero cap(ironman);
    cap.display();

    return 0;
}