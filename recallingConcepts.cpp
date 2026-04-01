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
    void setId(int id){             this->id = id;        }
    void setMarks(){
        for(int i=0; i<3; i++){
            cout << "Set Marks for Subject " << i+1 
                 << " for " << name << "(" << id << ")"<< ": ";
            cin >> marks[i];
        }
        cout << endl;
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

    friend istream &operator>>(istream &input, Student s){
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

    friend ostream &operator<<(ostream &output, const Student s){
        output << "Name: " << s.name << endl
               << "ID : "  << s.id   << endl;

        for(int i=0; i<3; i++)
            cout << "Subject " << i+1 << ": " << s.marks[i] << endl;
        
            return output;
    }
};


int main(){
    Student s1("Taha", 2501360);
    s1.setMarks();
    Student s2("Aisha", 2501363);
    s2.setMarks();
    Student s3("Tooba", 2501369);
    s3.setMarks();
    Student s4("Zaryab", 2501348);
    s4.setMarks();
    
    Student allStudents;

    allStudents = s1 + s2 + s3 + s4;

    cout << allStudents;
}