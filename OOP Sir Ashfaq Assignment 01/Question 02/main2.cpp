#include <iostream>
#include "Time.h"

using namespace std;

int main(){

    Time t(23, 59, 55);

    cout << "Testing tick function\n\n";

    for(int i = 0; i < 10; i++){
        t.printStandard();
        cout << endl;

        t.tick();
    }

    return 0;
}