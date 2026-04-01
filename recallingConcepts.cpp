// ___ Operator Overloading
#include<iostream>
using namespace std;

class Student{
    string name;
    int id;
    int marks[3];

    public:
    
    // ___ Constructor
    Student(string name="Unknown", int id=0){
        this->name = name;
        this->id = id;

        for(int i=0; i<3; i++)
            marks[i] = 0;
    }

    // ___ Setters
    void setName(string name){    this->name = name;    }
    void setId(int id){             this->id = id;        }
    void setMarks(int m1, int m2, int m3){
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    // ___ Getters
    string getName() const{           return name;      }
    int getId() const{                return id;        }
    const int* getMarks() const{      return marks;     }

    // ___ input Marks
    void inputMarks(int m1, int m2, int m3){
        for(int i=0; i<3; i++){
            cout << "Set Marks for Subject " << i+1 
                 << " for " << name << "(" << id << ")"<< ": ";
            cin >> marks[i];
        }
        cout << endl;
    }


    // ____ Operator Overloading ____
    // ___ (+) Overloading
    Student operator+(const Student &s){
        Student temp;

        temp.name = "Combined";
        temp.id = 0;
        for(int i=0; i<3; i++)
            temp.marks[i] = marks[i] + s.marks[i];

        return temp;
    }

    // ___ (+) Overloading with int
    friend Student operator+(int x, const Student &s){
        Student temp;

        temp.name = s.name;
        temp.id = s.id;
        for(int i=0; i<3; i++)
            temp.marks[i] = s.marks[i] + x;

        return temp;
    }

    // ___ (-) Overloading
    Student operator-(const Student &s){
        Student temp;

        temp.name = "Combined";
        temp.id = 0;
        for(int i=0; i<3; i++)
            temp.marks[i] = marks[i] - s.marks[i];

        return temp;
    }

    // ___ (-) Overloading with int
    friend Student operator-(int x, const Student &s){
        Student temp;

        temp.name = s.name;
        temp.id = s.id;
        for(int i=0; i<3; i++)
            temp.marks[i] = s.marks[i] - x;

        return temp;
    }


    // ____ Stream Operators Overloading ____
    // ___ (>>) Overloading
    friend istream &operator>>(istream &input, Student &s){
        cout << "Name: ";
        input >> s.name;
        cout << "ID: ";
        input >> s.id;
        cout << "*** Marks ***";
        for(int i=0; i<3; i++){
            cout << "Subject " << i+1 << ": ";
            input >> s.marks[i];
        }

        return input;
    }

    // ___ (<<) Overloading
    friend ostream &operator<<(ostream &output, const Student &s){
        output << "Name: " << s.name << endl
               << "ID : "  << s.id   << endl;

        for(int i=0; i<3; i++)
            output << "Subject " << i+1 << ": " << s.marks[i] << endl;
        
        return output;
    }


    // ____ Comparision Operators
    // ___ (<) Overloading
    bool operator<(const Student &s) const{
        if((marks[0]+marks[1]+marks[2])<(s.marks[0]+s.marks[1]+s.marks[2]))
            return true;

        return false;
    }

    // ___ (<) Overloading
    bool operator>(const Student &s) const{
        if((marks[0]+marks[1]+marks[2])>(s.marks[0]+s.marks[1]+s.marks[2]))
            return true;

        return false;
    }

    // ____ Post Increment/Decrement Operators ____
    Student operator++(int){
        Student temp = *this;  // copy old value
        id++;                  // increment current object
        return temp;           // return old value
    }

    Student operator--(int){
        Student temp = *this;  // copy old value
        id--;                  // increment current object
        return temp;           // return old value
    }

    // ____ Pre Increment/Decrement Operators ____
    Student &operator++(){
        id++;
        return *this;
    }

    Student &operator--(){
        id--;
        return *this;
    }

    // ____ Compound Assignment Operators
    // ___ (+=) Overloading 
    Student &operator+=(const Student &s){
        for(int i=0; i<3; i++)
            marks[i] += s.marks[i];

        return *this;
    }

    // ___ (-=) Overloading
    Student &operator-=(const Student &s){
        for(int i=0; i<3; i++)
            marks[i] -= s.marks[i];

        return *this;
    }
};


int main(){
    Student s1("Taha", 2501360);
    s1.setMarks(6, 7, 8);
    Student s2("Aisha", 2501363);
    s2.setMarks(7, 8 , 4);
    Student s3("Tooba", 2501369);
    s3.setMarks(8, 9, 8);
    Student s4("Zaryab", 2501348);
    s4.setMarks(8, 9, 6);
    
    Student allStudents;

    allStudents = s1 + s2 + s3 + s4;

    cout << allStudents;

    if(s1<s4)
        cout << "Zaryab has more Marks!";
    else
        cout << "Taha has more Marks!";
}