#include<iostream>
using namespace std;

template<class T1, class T2>
class sample {
  private:
    T1 a;
    T2 b;

  public:
    // ____ Generic Constructor
    sample(T1 x= T1(0), T2 y= T2(0)) : a(x),b(y){}

    void getdata(){
        cout << "Enter a and b: "<<endl;
        cin>> a >> b;
    }
    
    void display(){
        cout<<"Displaying values"<<endl;
        cout<<"a = "<< a << endl;
        cout<<"b = "<< b << endl;
    }

    void show();
};

// _____ How to define methods outside the generic class?
template<class T1, class T2>
void sample<T1, T2>::show(){
    cout << "Showing values" << endl;    
    cout << "a = " << a << endl;    
    cout << "b = " << b << endl;
}

int main() {    
    sample<int, int> s1;    
    sample<int, char> s2;    
    sample<int, float> s3;
    
    cout << "Two Integer data" << endl;    
    s1.getdata();    
    s1.display();
    
    cout << "Integer and Character data" << endl;    
    s2.getdata();    
    s2.display();
    
    cout << "Integer and Float data" << endl;
    s3.getdata();
    s3.display();
    s3.show();
    return 0;
}