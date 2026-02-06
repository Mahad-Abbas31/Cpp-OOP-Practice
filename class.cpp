#include<iostream>
#include<String>

using namespace std;

//  ==> Must declare access modifiers
// --> By Default, attributes, functions are private for a class in C++

class Teacher{
//____Attributes/Properties____

//___To Make Private (Not accessible directly in the program easily)
private:
    double salary;
  
//___To Make Public
public:
    string name;
    string dept;
    string address;
    string rank;

  //___Methods/Functions
    void changeDept(string newDept){
        dept = newDept;
    }

    //___ Setter Function (to set value of a private attribute)
    void setSal(double sal){
        salary = sal;
    }
    
    //___ Getter Function (to get value of a private attribute)
    double getSal(){
        return salary;
    }
};

int main(){
    Teacher T1;
    T1.name = "Rao Zubair";
    T1.dept = "Physics";
    T1.address = "Raja Ram Shujabad Multan";
    T1.rank = "Professor";
    
    cout << T1.name << endl << T1.dept << endl << T1.address << endl << T1.rank << endl;
    
    string newDept;
    cout << "Enter New Dept to Change Dept of the Teacher\n";
    cin >> newDept;
    T1.changeDept(newDept);

    double sal = 100000;
    T1.setSal(sal);
    
    cout << T1.name << endl << T1.dept << endl << T1.address << endl << T1.rank << endl << T1.getSal() << endl;
    return 0;
}