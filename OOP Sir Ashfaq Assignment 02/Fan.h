#ifndef FAN_H
#define FAN_H

#include <iostream>
using namespace std;

class Motor{
  private:
    int power;

  public:
    // ___Constructor
    Motor(int = 0);

    // ___Setter
    void setPower(int);
    
    // ___Getter
    int getPower();
};


class Owner{
  private:
    string name;

  public:
    // ___Constructor
    Owner(string = "Unknown");
    
    // ___Setter
    void setOwner(string);
    
    // ___Getter
    string getOwner();
};


class Fan{
  private:
    string brand;
    int speed;
    float price;

    // ___Composition
    Motor m;
    Owner o;

    // ___Static Members
    static int count;
    static int minSpeed;

  public:
    // ___Constructors & Destructor
    Fan();
    Fan(string,int,float,int,string);
    ~Fan();

    // ___Setters with Chaining
    Fan& setBrand(string);
    Fan& setSpeed(int);
    Fan& setPrice(float);

    // ___Setters without Chaining
    void setPower(int);
    void setOwner(string);

    // ___Show Method
    void show();

    // ___Static Methods
    static void showCount();
    static int getMinSpeed();

    // ___Getters
    int getSpeed();
    string getBrand();
    float getPrice();


    // ___Operator Overloading
    Fan operator+(Fan);

    // ___Friend Function
    friend void checkSpeed(Fan);
};

// ___Non-Member Functions
float averageSpeed(Fan*,int);
void lowSpeed(Fan*,int);

#endif