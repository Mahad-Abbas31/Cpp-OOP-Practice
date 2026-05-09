#include<iostream>
using namespace std;

template< class T >
class Complex {
  private:
    T x; // real part  
    T y; // imaginary part

  public:
    // ____ Generic Class Constructor
    Complex(T a = T(0), T b = T(0)) : x(a), y(b) {}

    // ____ Generic Class Getters
    T real() { return x; }
    T imag() { return y; }

    void display(){
        cout << x << endl << y << endl << endl;
    }
};

int main(){
    // ____ Using Generic Class
    Complex <int> zi(10, 20);
    Complex <double> zd(14.2, 51.4);
    Complex <string> zs("Hello", "Mahad");
    
    zi.display();
    zd.display();
    zs.display();

    return 0;

}