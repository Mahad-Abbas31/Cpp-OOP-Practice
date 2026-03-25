#include <iostream>

using namespace std;

class Box{
    int height;
    int widht;
    int length;

    static int count;

  public:
    Box(int h=0, int w=0, int l=0){
        height = h;
        widht = w;
        length = l;

        count++;
    }

    static int getCount(){
        return count;
    }

};

int Box::count = 0;

int main(){
    Box b1;
    Box b2;
    Box b3;
    Box b4;
    Box b5;

    cout << Box::getCount();
}