// ___ Operator Overloading

#include<iostream>
using namespace std;

class Student{
    string name;
    int id;
    int marks[3];

    public:
    
    Student(string name="Unknown", int id=0){
        this->name = name;
        this->id = id;

        for(int i=0; i<3; i++)
            marks[i] = 0;
    }

    void setName(string name){    this->name = name;    }
    void set(int id){             this->id = id;        }
    void set(){
        for(int i=0; i<3; i++){
            cout << "\nSet Marks for Subject " << i+1 << ": ";
            cin >> marks[i];
        }
    }

    string getName(){      return name;      }
    int getId(){           return id;        }
    int* getMarks() {      return marks;     }

    Student operator+(const Student s){
        Student temp;

        temp.name = "Combined";
        temp.id = 0;
        for(int i=0; i<3; i++)
            temp.marks[i] = marks[i] + s.marks[i];

        return temp;
    }
};


int main(){
    Student s1("Taha", 2501360);
}