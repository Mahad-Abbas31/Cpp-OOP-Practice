#include <iostream>

using namespace std;

// ___ Not Change 
// void func1(int i){
//     static int staticInt = i;   
//     cout << staticInt << endl;
// }

// ___ Change
// void func1(int i){
//     static int staticInt;
//     staticInt = i;   
//     cout << staticInt << endl;
// }

// ___ Dedault Value (0)
void func1(int i){
    static int staticInt;
    cout << staticInt << endl;
}


int main(){

    func1(1);
    func1(2);
    // ___ Error (Accces is Limited to the Function while LifeTime is throughout the Program)
    // cout << staticInt << endl;              

}
