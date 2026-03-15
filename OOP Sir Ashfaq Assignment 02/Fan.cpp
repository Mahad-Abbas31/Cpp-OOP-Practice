#include "Fan.h"
#include <iostream>

using namespace std;


// ___ Motor Methods ___
// ___Constructor
Motor::Motor(int power){              this->power = power;  }

// ___Setter
void Motor::setPower(int power){      this->power = power;  }

// ___Getter
int Motor::getPower(){                return power;         }


// ___ Owner Methods ___
// ___Constructor
Owner::Owner(string name){            this->name = name;    }

// ___Setter
void Owner::setOwner(string name){    this->name = name;    }

// ___Getter
string Owner::getOwner(){             return name;          }


// ___ Fan Methods ___
int Fan::count = 0;
int Fan::minSpeed = 2;

// ___Constructor
Fan::Fan(){
    brand = "Unknown";
    speed = 0;
    price = 0;
    count++;
}

// ___Fan Parameterized Constructor
Fan::Fan(string brand,int speed,float price,int power,string owner) : m(power), o(owner){
    this->brand = brand;
    this->speed = speed;
    this->price = price;
    count++;
}

// ___ Fan Destructor
Fan::~Fan(){    
    count--;
}


// ___Setters with Chaining
Fan& Fan::setBrand(string brand){
    this->brand = brand;
    return *this;
}

Fan& Fan::setSpeed(int speed){
    this->speed = speed;
    return *this;
}

Fan& Fan::setPrice(float price){
    this->price = price;
    return *this;
}


// ___Setters without Chaining
void Fan::setPower(int power){       m.setPower(power);    }
void Fan::setOwner(string owner){    o.setOwner(owner);    }


// ___Show Method
void Fan::show(){
    cout << brand << " "
         << speed << " "
         << price << " "
         << o.getOwner() << " "
         << m.getPower()
         << endl;
}


// ___Static Methods
void Fan::showCount(){
    cout << "Total Fans: " << count << endl;
}


// ___Getters
int Fan::getMinSpeed(){    return minSpeed;    }
int Fan::getSpeed(){       return speed;       }
string Fan::getBrand(){    return brand;       }
float Fan::getPrice(){     return price;       }

// ___Operator Overloading
Fan Fan::operator+(Fan f){
    Fan t;

    t.speed = speed + f.speed;
    t.price = price + f.price;
    t.brand = brand + "_" + f.brand;

    return t;
}


// ___Friend Function
void checkSpeed(Fan f){
    if(f.getSpeed() < Fan::getMinSpeed())
        cout << f.getBrand() << " Low Speed\n";
}


// ___Non-Member Functions
float averageSpeed(Fan *f,int n){
    float sum=0;

    for(int i=0;i<n;i++)
        sum += f[i].getSpeed();

    return sum/n;
}


// ___Low Speed Function
void lowSpeed(Fan *f,int n){
    for(int i=0;i<n;i++)
        checkSpeed(f[i]);
}