/*
--> Friends
    "A function or class outside of a class can be defined to be a friend
     by the class which gives the friend free access to the private
     (or protected) members of the class”

 -> Characteristics
    - friend keyword is given in declaration of the function in the class
    - friend keyword is given in definition of the function
    - Friend functions can be placed anywhere in the class without any effect
    - Access specifiers don’t affect friend functions or classes
    - Friendship is NOT bi-directional unless each class declares that the other is ​a friend 

 -> Why Used?

    - There are some private fields that you want to access but you don’t want to expose them publicly using interface
    - Similarly, one class can also be made friend of another class
    - “Friend” opens a small hole in the protective shield of the class, so it  should be used very carefully
    - You should implement this only when there is no way to solve your  programming problem

*/
#include<iostream>
using namespace std;

class Square; // ___ Forward Declaration

class Rectangle{
    int width;
    int length;
    int area;

    // ___ private: declared but no effect on its accessibility
    // ___ const Keyword used because the members of object does not change in displaying
    friend void display(const Rectangle r);
    
    // ___ Mutual Friend Function
    friend void setRectangleLength(Square &s,  const Rectangle r);
  public:

    Rectangle(int width = 0, int length = 0){
        this->width = width;
        this->length=length;
    }

    // ___ Friend class Usage (Accessing Private members of other class)
    void setLengthBySquare(const Square s){    length = s.length;    }

    // ___ public: declared but no effect on its accessibility
    // ___ const Keyword not used because the members of object changes (Area assigned) in displaying
    //     passed by reference (&r) to assign the value or change the vlaues of the members of the object
    friend void calArea(Rectangle &r);
    
    void calSquareArea(Square &s){
        s.area = s.length * s.length;
    }
};

class Square{
    int length;
    int area;

    friend Rectangle;
public:
    // ___ Mutual Friend Function
    friend void setRectangleLength(Square &s,const Rectangle r);

    Square(int length){    this->length = length;    }

    void display(){
        cout << "Length: " << length;
        cout << "\nArea  : " << area << endl;
    }
};

void calArea(Rectangle &r){    r.area = r.width * r.length;    }

void display(const Rectangle r){
    cout << "Length: " << r.length
         << "\nWidth : " << r.width
         << "\nAREA  : " << r.area << endl;
}

// ____ Mutual Friend Function
void setRectangleLength(Square &s, const Rectangle r){    s.length = r.length;    }

int main(){
    Rectangle r1(3, 6);

    calArea(r1);
    display(r1);
    Square s1(3);
    r1.calSquareArea(s1);

    s1.display();
}