#include<iostream>

using namespace std; 

class myarray{
    int* arr; 
    int size;

  public:
    myarray(int size){
        this->size = size;
        arr = new int[size];

        for(int i=0; i<=size; i++)
            arr[i] = i+1;
    }

    int operator[](int index){
        if (index >= size)
            cout << "Array out of bound" << endl; 
            // exit(0);

        return arr[index];
    }
};

int main(){
    myarray arr(10);  
    // int x;  
    // x = arr[10];

    for(int i=0; i<=10; i++)
        cout << "[" << i << "] = " << arr[i]  << endl; 
    
    return 0;
}