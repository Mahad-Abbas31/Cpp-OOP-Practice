#ifndef HERO_H
#define HERO_H

#include<string>
#include<iostream>

using namespace std;

class Hero{
    string identity;
    string name;
    string power;
    string region;
    int level;
    int stars;
    int health;

public:
    Hero();
    Hero(string i, string n, string p, string r, int l, int s); 
    Hero(const Hero &obj);

    void display();

        // ___ SetterFunctions
    void setIdentity(string identity);    
    void setName(string name);
    void setPower(string power);
    void setregion(string region);
    void setlevel(int level);
    void setStars(int stars);

    // ___ GetterFunctions
    string getIdentity();
    string getName();
    string getpower();
    string getregion();
    int getlevel();
    int getStars();

    // ___ Level Changing Methods
    void increaseLevel();
    void decreaseLevel();

    
    void championList(Hero arr[], int size);

    
    void lightAttack1(Hero &enemy);
    void highAttack1(Hero &enemy);
    void lightAttack2(Hero &enemy);
    void highAttack2(Hero &enemy);
    void special1(Hero &enemy);
    void special2(Hero &enemy);
};

#endif