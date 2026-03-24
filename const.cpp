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
    int getX() const {    return x;    }        // const function
};


// ___ FUNCTION Parameters ___
void print(const math &s);



// ___ MAIN Function ___
int main(){
    // ___ CASE 1: const variable
    const int x = 10;
    // x = 20;   // ❌ Error


    // ___ CASE 2: const objects
    const math t;
    // t.x = 5;   // ❌ Error

}

// ___ FUNCTIONS ___

// ___ CASE 4: const with function parameters (pass by reference)
void print(const math &s) {
    // s.x = 50;  // ❌ not allowed
}