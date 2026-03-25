/*
--> Static Member Function
    "A static member function is a function that belongs 
     to the class itself, not to objects. It can access 
     only static data members of the class."

-> Characteristics
    - belongs to class
    - shared by all objects
    - can be called without object
    - (this->) pointer not allowed in Static Member Functions
    - can only access static data members

-> Why we use static member function
    - Data is shared by all objects
    - Function does not depend on object
    - Need class-level operation
    -> Example: counter, total objects, settings, utilities.

-> Calling Static Function
    - ClassName::functionName();
    - obj.functionName();
*/
#include <iostream>

using namespace std;

class Box{
    int height;
    int width;
    int length;

    static int count;

    public:

    Box(int w=0, int l=0, int h=0){
        width = w;
        length = l;
        height = h;

        count++;
    }

    static int getCount(){    return count;    }

    static void showCount() {
        cout << count;
        // cout << height;               // ___ ❌ not allowed (non static data member)
    }
};

int Box::count = 0;

int main(){
    Box b1, b2, b3, b4, b5;

    cout << "No. of Boxes: " << Box::getCount();
}