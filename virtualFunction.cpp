/*
--> VIRTUAL FUNCTION
    "A virtual function is a member function of a class that is declared using
    the keyword virtual and is designed to be overridden in a derived class so
    that the correct function is called at runtime based on the actual object type."

    - It lets C++ decide which function to call while the program is running, not before. 

 -> Why Do We Need Virtual Functions?
    - Without virtual functions, C++ uses early binding (compile-time).
    - With virtual functions, C++ uses late binding (runtime).

 -> Problem without virtual:
    Base* ptr = new Derived();
    ptr->show();   // Calls Base version ❌

    👉 With virtual:
    virtual void show();

    Now:
    ptr->show();   // Calls Derived version ✅

 -> How it Works:
    ✔Inheritance
    ✔Function overriding
    ✔Base class pointer/reference
    ✔ Compiler checks pointer type → Base
    ✔ Runtime checks actual object → Derived
    ✔ Calls Derived function

 -> Rules
    ✔✅ Must be inside a class
        (Not allowed as global function)
    ✔✅ Declared in base class using virtual
    ✔✅ Same function signature in derived class
        (Name + parameters must match)
    ✔✅ Accessed via pointer/reference
        Base* ptr;
    ✔✅ Automatically virtual in derived classes
        (No need to write virtual again)
    ✔❌ Constructors cannot be virtual
    ✔✅ Destructors should be virtual (important)
    ✔Virtual Function cannot be Static function or stand alone function

 -> Quick Summary (Exam Ready)
    ✔Virtual function → runtime polymorphism
    ✔Declared in base class using virtual
    ✔Overridden in derived class
    ✔Called using base pointer/reference
    ✔Pure virtual → = 0
    ✔Abstract class → cannot instantiate
    ✔Use override for safety
    ✔Use virtual destructor
*/
#include<iostream>
using namespace std;

class Person{
  protected:
    string name;
    string address;
    string role;
    bool disability;
    int age;

  public:
    Person(string n="", string a="", string r="", bool d=false, int i=0){
        name = n;
        age = i;
        address = a;
        role = r;
        disability = d;
    }

    void setName(string n){         name = n;          }
    void setAddress(string a){      address = a;       }
    void setRole(string r){         role = r;          }
    void setDisability(bool d){     disability = d;    }
    void setAge(int a){             age = a;           }

    string getName(){                   return name;          }
    string getAddress(){                return address;       }
    string getRole(){                   return role;          }
    bool getDisability(){               return disability;    }
    int getAge(){                       return age;           }

    virtual void doTask(){
        cout << "Person will be doing his Task according to his Role\n";
    }

    virtual ~Person(){}
};

class Student: public Person{
  protected:
    int id;
    int fee;

  public:
    Student(string n="", string a="", bool d=false, int i=0, int f=0, int id=0) 
        : Person(n, a, "Student", d, i), fee(f), id(id){}

    void doTask () override{
        cout << role << " is studying....\n";
    }
};

class Teacher: public Person{
  protected:
    int id;
    int pay;

  public:
    Teacher(string n="", string a="", bool d=false, int i=0, int f=0, int id=0)
        : Person(n, a, "Teacher", d, i), pay(f), id(id){}

    void doTask () override{
        cout << role << " is teaching....\n";
    }
};

class Cook: public Person{
  protected:
    int experience;
    int pay;

  public:
    Cook(string n="", string a="", bool d=false, int i=0, int f=0, int exp=0)
        : Person(n, a, "Cook", d, i), pay(f), experience(exp){}

    void doTask () override{
        cout << role << " is cooking....\n";
    }
};

int main(){
    Person* p;
    Person q;

    Student s("Ali", "Lahore", false, 20, 50000, 101);
    Teacher t("Ahmed", "Karachi", false, 40, 80000, 201);
    Cook c("Bashir", "Islamabad", false, 35, 30000, 10);

    p = &s;
    p->doTask();    // dynamic binding

    p = &t;
    p->doTask();    // dynamic binding

    p = &c;
    p->doTask();    // dynamic binding

    q.doTask();
    delete p;

    return 0;
}