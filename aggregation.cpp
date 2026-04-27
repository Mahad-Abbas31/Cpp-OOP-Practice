/*
--> What is Aggregation?
    "Aggregation is a weak “has-a” relationship where 
    One class uses another class, but does NOT own it."

✔ Aggregation is a special form of association that represents an ownership
   relationship between two objects. Aggregation models has-a relationships.
✔ The owner object is called an aggregating object, and its class is called an aggregating class.
✔ The subject object is called an aggregated object.
✔ Its class is called an aggregated class.
✔ Objects are independent
✔ If one object is destroyed → the other still exists

 -> Real-life examples:
    ✔ A Department has Teachers
    ✔ A Library has Books
    ✔ A Team has Players
    👉 If the department closes → teachers still exist

 -> Aggregation is typically implemented using:
    ✔ Pointers or references

 -> Teacher exists independently
    ✔ Department just uses Teacher
    ✔ Department does NOT create or destroy Teacher
    👉 This is aggregation

 -> Key Characteristics
    ✔ Weak relationship
    ✔ No ownership
    ✔ Independent lifetime
    ✔ Uses pointers/references
    ✔ Flexible design
    ✔ An object may contain a collection (aggregate) of other objects
    ✔ The relationship between the container and the contained object is called aggregation
    ✔ Aggregation is represented by a line with unfilled-diamond head towards the container
*/