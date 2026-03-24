#include <iostream>

using namespace std;



// ___ MATH Class ___
class math{
  public:
    int x;

    math(){    x = 10;    }

    // ___ (SETTERs)
    void setX(int m) {    x = m;       }

    // ___ CASE 3: const member function (GETTERs)
    int getX() const {    return x;    }        // ___ const function
};


// ___ FUNCTION Parameters ___
void print(const math &s);



// ___ MAIN Function ___
int main(){
    // ___ CASE 1: const variable
    const int x = 10;
    // x = 20;                     // ___ ❌ Error


    // ___ CASE 2: const objects
    const math t;
    // t.x = 5;                    // ___ ❌ Error


    // ___ CASE 5: ptr to const obj
    math m1;
    math m2;
    const math *ptr = &m1;

    ptr = &m2;                     // ___ ✅ OK
    // ptr->setX(50);              // ___ ❌ Error 


    // ___ CASE 6: const ptr to obj
    math * const ptr2 = &m1;
    // ptr2 = &m2;                 // ___ ❌ Error 
    ptr2->setX(50);                // ___ ✅ OK    
    
    
    // ___ CASE 7: const ptr to const obj
    const math * const ptr3 = &m1;
    // ptr3 = &m2;                 // ___ ❌ Error 
    // ptr3->setX(50);             // ___ ❌ Error 
    
    

}

// ___ FUNCTIONS ___

// ___ CASE 4: const with function parameters (pass by reference)
void print(const math &s) {
    // s.x = 50;                  // ___ ❌ Error 
}