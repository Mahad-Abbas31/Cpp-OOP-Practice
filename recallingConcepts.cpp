#include <iostream>
using namespace std;

// class Rectangle{
//     int width, height;
//     static int NoOfRectangles;

// public:
//     Rectangle(){
//         width = 0;
//         height = 0;
//         NoOfRectangles++;
//     }

//     static int getTotalRectangles(){
//         return NoOfRectangles;
//     }
        
// };

// int Rectangle::NoOfRectangles=0;

// int main(){
//     Rectangle r1;
//     Rectangle r2;
//     Rectangle r3;
//     Rectangle r4;
//     Rectangle r5;
//     cout << Rectangle::getTotalRectangles ();
// }


class Test{
    int i,j;

public:
    Test(int x, int y){
        i=x;
        j=y;
    }

    void display(){
        cout << "i: " << i << ", j: " << j << endl;
    }

    void displayArray(Test arr[], int size){
        for(int k=0; k<size; k++){
            arr[k].display();
        }
    }
};

int main(){

    Test a(1,1), b(2,2);
    Test array[2]= {a,b};
    
    a.displayArray(array, 2);
}