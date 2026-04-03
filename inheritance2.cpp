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
________________________________________________________________________

*/

#include<iostream>

using namespace std;

int main(){

}