#include <iostream>

using namespace std;

class Parent{

    public:
    Parent(int a = 0){
        cout << "Parent Constructor...";
    }


};


class Child : public Parent{

    public:
    Child(){
        cout << "Child Constructor...";
    }
};


int main(){

    Child cobj;
    return 0;
}