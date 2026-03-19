/*
--> POINTER TO OBJECTS
        "A pointer to object means a pointer variable that stores the
         address of an object of a class."

    _______________________________________
         Access     -       Use      
    ---------------------------------------
       obj.x        -    normal object  
       ptr->x       -    pointer object 
       (*ptr).x     -    same as ptr->x 
    _______________________________________

 -> WHY USED?
     - Dynamic memory allocation
     - Arrays of objects
     - Passing objects to functions
     - Using new keyword


    ____________________________________________
        SYNTAX	      -         MEANING
    --------------------------------------------
    Test *ptr;	      -      pointer to object
    ptr = &obj;	      -      store address
    ptr->var	      -      access member
    ptr->func()	      -      call function
    ____________________________________________

    
*/


#include <iostream>
using namespace std;

class Test {
public:
    int x;

    void show(){
        cout << "x = " << x << endl;
    }
};

int main(){
// ___ Basic Example
    // Test t1;
    // Test *ptr;   // pointer to object

    // ptr = &t1;   // store address of object

    // ptr->x = 10; // access using ->
    // ptr->show();


    // return 0;


// ___ Dynamic Object (new)
    // Test *ptr;

    // ptr = new Test;   // dynamic object

    // ptr->x = 50;
    // ptr->show();

    // delete ptr;

    // return 0;


// ___ Pointer to Array of Objects (new)
    // Test *s;

    // int num;
    // cin >> num;

    // s = new Test[num];

    // for(int i=0;i<num;i++)
    //     s[i].x = i+1;

    // for(int i=0;i<num;i++)
    //     s[i].show();

    // delete[] s;
    // return 0;


// ___ Pointer to Object as Function Parameter (PART 1)
    Test t1;

    display(&t1);
}



// ___ Pointer to Object as Function Parameter (PART 2)
void display(Test *p){
    p->show();
}