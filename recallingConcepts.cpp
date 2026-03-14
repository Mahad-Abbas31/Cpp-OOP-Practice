#include <iostream>
using namespace std;

class Rectangle{
    int width, height;
    static int NoOfRectangles;

public:
    Rectangle(){
        width = 0;
        height = 0;
        NoOfRectangles++;
    }

    static int getTotalRectangles(){
        return NoOfRectangles;
    }
        
};

int Rectangle::NoOfRectangles=0;

int main(){
    Rectangle r1;
    Rectangle r2;
    Rectangle r3;
    Rectangle r4;
    Rectangle r5;
    cout << Rectangle::getTotalRectangles ();
}
