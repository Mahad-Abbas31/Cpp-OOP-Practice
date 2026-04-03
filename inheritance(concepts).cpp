/*
 1) Generalization
    "Generalization is the process of extracting common characteristics from 
    two or more classes and creating a single generalized (parent) class."

 -> Explanation:
    In object-oriented design, many classes may share similar attributes and behaviors.
    Instead of repeating the same code, these common features are placed in a base class. 
    The specific classes then inherit from this general class.

 -> Why we use it?
    - To reduce code duplication
    - To improve reusability
    - To simplify system design

 -> Example (Conceptual)
    - Classes like Car, Bike, and Truck can be generalized into a parent class Vehicle.

 -> Key Features:
    - Follows a bottom-up approach
    - Combines similar classes
    - Promotes code reuse
______________________________________________________________________________________
 2) Subtyping (Extension)
    "Subtyping is a concept where a class (child class) is considered a subtype
     of another class (parent class) and can be used wherever the parent class is expected."

 -> Explanation
    A subtype inherits all properties of the parent class and may also include 
    additional features or behaviors. It represents an "IS-A" relationship.

 -> Why we use it?
    - To extend existing functionality
    - To support polymorphism
    - To allow flexible and reusable code
    
 -> Example (Conceptual)
    - A Dog is a subtype of Animal. It inherits general features like eating and 
      sleeping, but also has its own feature like barking.

 -> Key Features
    - Based on inheritance
    - Follows "IS-A" relationship
    - Adds new functionalities
    - Supports polymorphism
________________________________________________________________________________________
 3) Specialization (Restriction or Overriding)
    "Specialization is the process of creating a new class from an existing
     class by adding specific features or modifying existing ones."

 -> Explanation
    In specialization, a child class becomes more specific than its parent by refining
    or overriding certain behaviors. It may also restrict some features of the parent class.

 -> Why we use it?
    - To represent more specific behavior
    - To customize inherited features
    - To improve flexibility in design

 -> Example (Conceptual):
    - An Animal class may have a method makeSound(), but a Dog class 
    overrides it to define a specific sound (bark).

 -> Key Features:
    - Follows a top-down approach
    - Uses method overriding
    - Makes classes more specific
    - Can restrict or redefine behavior

________________________________________________________________________
     Concept        -    Approach     -                Focus           
------------------------------------------------------------------------
 Generalization     -   Bottom-up     -    Combine common features     
 Subtyping          -   Top-down      -    Extend functionality        
 Specialization     -   Top-down      -    Refine or override behavior 
________________________________________________________________________*/

#include<iostream>

using namespace std;

class Person{
    string name;
    int age;
    string gender;

    public:
    // ____ Constructor
    Person(string name = "Unknown", int age = 0, string gender = "Unknown") {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }

    // ____ Setters 
    void setName(string name){          this->name = name;       }
    void setAge(int age){               this->age = age;         }  
    void setGender(string gender){      this->gender = gender;   }

    // ____ Getters
    string getName() const{             return name;             }
    string getGender() const{           return gender;           }
    int getAge() const{                 return age;              }

    // ____ Behaviors
    void eat() const{
        cout << name << " is eating." << endl;
    }

    void walk() const{
        cout << name << " is walking." << endl;
    }

    void sleep() const{
        cout << name << " is sleeping." << endl;
    }
};

class Student: public Person{
    string program;
    int rollNumber;
    int semester;

    public:

    // ____ Constructor
    Student(string n="Unknown", int a=0, string g="Unknown", string p="Unknown", int r=0, int s=0) : Person(n, a, g){
        program = p;
        rollNumber = r;
        semester = s;
    }

    // ____ Setters 
    void setProgram(string program){            this->program = program;           }
    void setRollNumber(int rollNumber){         this->rollNumber = rollNumber;     }
    void setSemester(int semester){             this->semester = semester;         }

    // ____ Getters
    string getProgram() const{          return program;          }
    int getRollNumber() const{          return rollNumber;       }
    int getSemester() const{            return semester;         }

    // ____ Additional Behaviors
    void study() const{
        cout << getName() << " is studying." << endl;
    }

    void attendClass() const{
        cout << getName() << " is attending class." << endl;
    }
};

class Teacher : public Person{
    string designation;
    string university;

    public:
    // ____ Constructor   
    Teacher(string d="Unknown", string u="Unknown", string n="Unknown", int a=0, string g="Unknown") : Person(n, a, g){
        this->designation = d;
        this->university = u;
    }

    // ____ Setters
    void setDesignation(string designation){    this->designation = designation;    }
    void setUniversity(string university){      this->university = university;      }

    // ____ Getters
    string getDesignation() const{      return designation;     }
    string getUniversity() const{       return university;      }

    // ____ Additional Behaviors
    void teach() const{
        cout << getName() << " is teaching." << endl;
    }

    void takeExam() const{
        cout << getName() << " is taking an exam." << endl;
    }
};

class Doctor : public Person{
    string specialization;
    string hospital;

    public:
    // ____ Constructor
    Doctor(string s="Unknown", string h="Unknown", string n="Unknown", int a=0, string g="Unknown") : Person(n, a, g){
        this->specialization = s;
        this->hospital = h;
    }

    // ____ Setters
    void setSpecialization(string specialization){   this->specialization = specialization;   }
    void setHospital(string hospital){               this->hospital = hospital;               }

    // ____ Getters
    string getSpecialization() const{   return specialization;  }
    string getHospital() const{         return hospital;        }

    // ____ Additional Behaviors
    void checkup() const{
        cout << getName() << " is doing a checkup." << endl;
    }

    void prescribe() const{
        cout << getName() << " is prescribing medicine." << endl;
    }
};


int main(){

}