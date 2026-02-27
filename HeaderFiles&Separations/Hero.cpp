#include<iostream>
#include<fstream>
#include"Hero.h"
#include<cstdlib>
#include<ctime>

using namespace std;

    // - Non-parameterized constructors.
    Hero::Hero(){
        identity = "Unknown";
        name = "Unknown";
        power = "Unknown";
        region = "Unknown";
        level = 0;
        stars = 0;
        health = 100;
    }
    
    // - Parameterized constructors.
    Hero::Hero(string identity, string name, string power, string region, int level, int stars){
        this->identity = identity;
        this->name = name;
        this->power = power;
        this->region = region;
        this->level = level;
        this->stars = stars;
        this->health = 100;
    }

    // ___ Copy Constructor
    Hero::Hero(const Hero &obj){
        identity = obj.identity;
        name = obj.name;
        power = obj.power;
        region = obj.region;
        level = obj.level;
        stars = obj.stars;
        health = 100;
    }

    //___ Dispaly Function
    void Hero::display(){
        cout << identity << endl;
        cout << name << endl;
        cout << power << endl;
        cout << region << endl;
        cout << level << endl;

        for(int i=0; i<=stars; i++)    cout << "*";
        cout << endl;
        
        for(int i=0; i<health; i++)    cout << "|";
        cout << endl;
    }

    // ___ SetterFunctions
    void Hero::setIdentity(string identity){    this->identity = identity;    }
    
    void Hero::setName(string name){    this->name = name;    }
    
    void Hero::setPower(string power){    this->power = power;    }
    
    void Hero::setregion(string region){    this->region = region;    }
    
    void Hero::setlevel(int level){    this->level = level;    }
    
    void Hero::setStars(int stars){    this->stars = stars;    }

    // ___ GetterFunctions
    string Hero::getIdentity(){    return identity;    }

    string Hero::getName(){    return name;    }

    string Hero::getpower(){    return power;    }

    string Hero::getregion(){    return region;    }

    int Hero::getlevel(){    return level;    }

    int Hero::getStars(){    return level;    }

    // ___ Level Changing Methods
    void Hero::increaseLevel(){    level = level + 1;    }

    void Hero::decreaseLevel(){    if(level > 1)    level = level -1;    }

    
    void Hero::championList(Hero arr[], int size){
        ifstream fin("champions.txt");
            
        for(int i=0; i<5; i++){
            fin >> arr[i].identity >> arr[i].name
                >> arr[i].power >> arr[i].region
                >> arr[i].level >> arr[i].stars;
        }

        fin.close();
    }

    // ___ Attack Methods
    void Hero::lightAttack1(Hero &enemy){
        enemy.health = enemy.health - (rand()%5 + 2);    
        if(enemy.health < 0)
            enemy.health = 0;
    }

    void Hero::highAttack1(Hero &enemy){    
        enemy.health = enemy.health - (rand()%9 + 4);
        if(enemy.health < 0)
            enemy.health = 0;    
    }

    void Hero::lightAttack2(Hero &enemy){    
        enemy.health = enemy.health - (rand()%5 + 2);    
        if(enemy.health < 0)
            enemy.health = 0;
    }

    void Hero::highAttack2(Hero &enemy){    
        enemy.health = enemy.health - (rand()%9 + 4);    
        if(enemy.health < 0)
            enemy.health = 0;
    }

    void Hero::special1(Hero &enemy){    
        enemy.health = enemy.health - (rand()%15 + 7);            
        if(enemy.health < 0)
            enemy.health = 0;
    }

    void Hero::special2(Hero &enemy){    
        enemy.health = enemy.health - (rand()%15 + 7);    
        if(enemy.health < 0)
            enemy.health = 0;
    }
