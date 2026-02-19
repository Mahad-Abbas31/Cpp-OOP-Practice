#include<iostream>

using namespace std;

class Avenger{
    int id;
    string name;
    string realIdentity;
    string power;

    public:

    // ___ Default Constructor
    Avenger(){
        id = 0;
        name = "Unknown";
        realIdentity = "Unknown";
        power = "Unknown";
    }
    
    // ___ Parameterized Constructor
    Avenger(int id, string name, string realIdentity, string power){
        this->id = id;
        this->name = name;
        this->realIdentity = realIdentity;
        this->power = power;
    }

    // ___ Copy Constructor
    Avenger(const Avenger& a){
        id = a.id;
        name = a.name;
        realIdentity = a.realIdentity;
        power = a.power;
    }

    // ___ Setter Functions (By Functions Chaining using Returning
    //     Reference with (this->) Pointer)
    Avenger& setId(int id){
        this->id = id;
        return *this;
    }

    Avenger& setName(string name){
        this->name = name;
        return *this;
    }
    
    Avenger& setRealIdentity(string realIdentity){
        this->realIdentity = realIdentity;
        return *this;
    }
    
    Avenger& setPower(string power){
        this->power = power;
        return *this;
    }

    // ___ Getter Functions
    int getId(){
        return id;
    }

    string getName(){
        return name;
    }

    string getRealIdentity(){
        return realIdentity;
    }

    string getpower(){
        return power;
    }

    // ___ DisplayData
    void displayAvenger(){
        cout << "\nID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Real Identity: " << realIdentity << endl;
        cout << "Power: " << power << endl;
        cout << "___________________________________" << endl;
    }
};

int main(){
    Avenger a1;
    a1.displayAvenger();

    // ___ Calling Functions through Chaining
    a1.setId(001).setName("Ironman").setRealIdentity("TonyStark").setPower("Intelligence");

    a1.displayAvenger();
    
    Avenger a2=a1;
    
    Avenger a3(3, "CaptainAmerica", "SteveRoggers", "SuperSerum+VibraniumShield");
    
    a2.displayAvenger();
    a3.displayAvenger();
    
    return 0;
}