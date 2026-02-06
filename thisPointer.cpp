#include <iostream>

using namespace std;
/*
--> this PPOINTER:
      "The this pointer is a special pointer
       that holds the address of the current 
       calling object inside a class member function."

 -> WHY IS 'this' POINTER USED?
     It is mainly used to:
    - Differentiate between data members and parameters when they have the same name.
    - Return the current object from a function.
    - Pass the current object as an argument to another function.
    - "this->name" is same as "*(this).name"

*/
class Hero{
    string name;
    string power;
    string region;
    int level;
    int stars;
    
public:
    Hero(){
        cout << "I am an Avenger!";
    }
    
    //__ Using "this" to resolve naming conflict
    Hero(string name, string power, string region, int level, int stars){
        this->name = name;
        this->power = power;
        this->region = region;
        this->level = level;
        this->stars = stars;
    }

     //__ USING "this" TO RETURN CURRENT OBJECT
    Hero& upgradeLevel(int newLevel){
        this->level = newLevel;   // modify current object
        return *this;             // return the SAME object
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

    //__ Using returned current object
    ironman.upgradeLevel(60).display();

}