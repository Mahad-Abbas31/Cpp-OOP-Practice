#include<iostream>
#include<string>

using namespace std;


/*
--> COPY CONSTRUCTOR
        "The static keyword in C++ is used to control the lifetime 
        and visibility of variables and class members. Its meaning 
        depends on where it is used.."

 -> 1. Static Local Variable (inside a function)
     - A static local variable keeps its value between function calls.
     - It is initialized only once.
     - Its lifetime lasts for the entire program.
     - But its scope is still limited to the function.

 -> 2. Static Data Member (in a class)
     - A static data member belongs to the class itself, not to individual objects.
     - Only one copy exists for all objects.
     - Shared by every object of the class. 
> NOTE:
     - Static members can be accessed using the class name, without creating an object.
     - Static members must be defined outside the class definition, and initialized if necessary.

 -> 3. Static Member Function
     - A static function in a class can access only static members.
     - It belongs to the class, not objects.
     - It can be called using the class name.
    
*/

//  ___ Static Local Variable (inside a function)
void counter(){
    static int count = 0;   // initialized once
    count++;
    cout << "Count: " << count << endl;
}


// ___ Static Data Member (in a class)
class Student{
public:
    static int count;
    Student(){    count++;    }
};
int Student::count = 0;


// ___ Static Member Function
class Test{
public:
    static void show(){    cout << "Static Function";    }
};


int main(){
//  ___ Static Local Variable (inside a function)
    counter();
    counter();
    counter();

// ___ Static Data Member (in a class)
    Student s1;
    cout << Student::count << endl;

    Student s2;
    cout << Student::count << endl;

    Student s3;
    cout << Student::count << endl;

// ___ Static Member Function
    Test::show();

    return 0;
}