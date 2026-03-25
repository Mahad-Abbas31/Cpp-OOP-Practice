#include<iostream>

using namespace std;

class Box{
    int height;
    int width;
    int length;

    static int count;

    public:

    Box(int w, int l, int h){
        width = w;
        height = h;
        length = l;

        count++;
    }

    Box operator+(Box b){
        Box temp(0, 0, 0);

        temp.width = this->width + b.width;
        temp.height = this->height + b.height;
        temp.length = this->length + b.length;

        return temp;
    }

    void display(){
        cout << "Height: " << height << endl
             << "Width: " << width << endl
             << "Length: " << length << endl;
    }
};

int Box::count = 0;

int main(){
    Box b1(2,3,4), b2(4,5,6);

     (b1+b2).display();
}