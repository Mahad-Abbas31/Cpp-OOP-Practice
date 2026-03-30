#include <iostream>
using namespace std;

class Rectangle;  // 👈 Forward declaration

class Square{
    int	width,	height;  
  public:

    void set_values(int	x,	int	y);
    friend void add(Square, Rectangle);
};

void Square::set_values(int x, int y){  
    width = x;
    height = y;
}


class Rectangle{
    int	width, height;
  public:

    void set_values(int	x, int y);
    friend void add(Square, Rectangle);

};

void Rectangle::set_values(int x, int y){  
    width = x;
    height = y;
}

void add(Square A, Rectangle B){
    cout << "Width = "<< A.width + B.width<< endl;
    cout << "Height = " << A.height + B.height <<  endl;
}

int main() {
    Square s;  
    Rectangle r ;
    s.set_values(1,1);
    r.set_values(2, 3);  
    add(s, r);
    
    return 0;
}

