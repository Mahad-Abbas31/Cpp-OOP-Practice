/*
--> Generic Programming?
    "Generic programming is a technique where functions, 
    classes, or data structures are written in a way that
    they can work with any data type."

 -> Instead of writing separate code for int, float, string, etc.,
    you write one reusable code.

 -> Why Use Generics?
    - Code reusability ♻️
    - Type safety ✅
    - Reduces duplication
    - Easier maintenance

 -> In C++ generic programming is done using templates
    - Two kinds
    - Function Templates
    - Class Templates
    - Compiler generates different type-specific copies from a single template
    - A template may not handle all the types successfully
    - Explicit specializations need to be provided for specific type(s)
*/

#include <iostream>
using namespace std;

template<class A>
void compare(A x, A y){
    if(x<y)
        cout << y << " is bigger\n";
    if(x>y)
        cout << x << " is bigger\n";
    if(x==y)
        cout << x << " and " << y << " are equal\n";
}

template<class A>
A getInput(){
    A a;
    cin >> a;
    return a;
}


// Generic Template
template <typename T>
bool isEqual(T x, T y){
    return (x == y);
}

// Specialization for string
template <>
bool isEqual<string>(string x, string y){
    return (x==y);   
}

int main(){
    compare(1,2);
    compare(1.3,2.2);
    compare('A','A');

    // compare(11.2, 10);          Error(float and int)
    compare<float>(11.3, 10);
    compare<int>(11.3, 10);

    // getInput();                  Error(No Clue of the datatype)
    int x;
    x = getInput<int>();            // Ok!

    double y;
    y = getInput<double>();         // Ok!


    cout << isEqual(5, 6) << endl; // ok
    cout << isEqual(7.5, 7.5) << endl; // ok

    string a = "hello";
    string b = "hello";

    cout << isEqual(a, b) << endl; // ok
    
    return 0;
}