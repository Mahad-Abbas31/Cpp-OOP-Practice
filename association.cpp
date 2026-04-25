/*
--> Association
    "Association is a relationship between two classes where
     objects of one class are connected to objects of another class."/
    “One class uses or works with another class.”

✔ It is a “has-a” relationship
✔ It represents real-world connections

 -> Real-life examples:
    These are associations, not ownership necessarily.
    ✔ A Teacher teaches Students
    ✔ A Customer places Orders
    ✔ A Driver drives a Car

 -> In C++, association is implemented using:
    ✔ Pointers
    ✔ References
    ✔ Objects as members (sometimes)

 -> Types of Association
    1. Composition (Hollowed Diamond)
    2. Aggregation (Filled Diamond)
    
    3. Simple Association (Straight Line)
      ✔ Is the weakest link between objects
      ✔ Is a reference by which one object can interact with some other object
      ✔ Is simply called as “association”
      
      > Kinds of Simple Association (W.R.T Navigation)
        i. One-Way Association
            - We can navigate along a single direction only
            - Denoted by an arrow towards the server object

        ii. Two-Way Association
            - We can navigate in both directions
            - Denoted by a line between the associated objects
    
      > Kinds of Simple Association (W.R.T No. of Objects)
        i. Binary Association
            - Associates objects of exactly two classes
            - Denoted by a line, or an arrow between the associated objects

        ii. Ternary Association
            - Associates objects of exactly three classes
    
        iii. N-ary Association
            - An association between 3 or more classes
            - Practical examples are very rare

        > Multiplicity
            - One-to-One
            - One-to-Many
            - Many-to-Many

*/