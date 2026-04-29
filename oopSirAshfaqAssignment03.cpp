#include<iostream>
using namespace std;

// ____ Base Class (Places)
class Places{
    int p_ID;
    string name;
    string location;
  public:
    // ____ Default Constructor
    Places(){
        p_ID = 0;
        name = "";
        location = "";
    }

    // ____ Parameterized Constructor
    Places(int i, string n, string l){
        p_ID = i;
        name = n;
        location = l;
    }

    // ____ Setters
    void setp_ID(int i){            p_ID = i;          }
    void setName(string n){         name = n;          }
    void setLocation(string l){     location = l;      }
    
    // ____ Getters
    int getp_ID(){               return p_ID;           }
    string getName(){            return name;           }
    string getLocation(){        return location;       }
    
    // ____ toString
    string toString(){
        return to_string(p_ID) + "\t" + name + "\t" + location;
    }
};

// ____ Derived Class (Park)
class Park : public Places{
    int no_ofTrees;
    int ticket;
    bool kidsArea;
    bool joggingTrack;
    bool refreshment;
  public:
    // ____ Default Constructor
    Park() : Places(){
        no_ofTrees = 0;
        ticket = 0;
        kidsArea = false;
        joggingTrack = false;
        refreshment = false;
    }
    
    // ____ Parameterized Constructor
    Park(int i, string n, string l, int tree, int ti, bool b1, bool b2, bool b3)
         : Places(i, n, l), no_ofTrees(tree), ticket(ti), kidsArea(b1), joggingTrack(b2), refreshment(b3){}

    // ____ Setters
    void setNo_ofTrees(int t){          no_ofTrees = t;            }
    void setTicket(int t){              ticket = t;                }
    void setKidsArea(bool b){           kidsArea = b;              }
    void setJoggingTrack(bool b){       joggingTrack = b;          }
    void setRefreshment(bool b){        refreshment = b;           }

    // ____ Getters
    int getNo_ofTrees(){                return no_ofTrees;         }
    int getTicket(){                    return ticket;             }
    bool getKidsArea(){                 return kidsArea;           }
    bool getJoggingTrack(){             return joggingTrack;       }
    bool getRefreshment(){              return refreshment;        }

    // ____ Inherited toString
    string toString(){
        return Places::toString() + "\t" + to_string(no_ofTrees) + "\t" + to_string(ticket) + "\t" + to_string(kidsArea) + 
                "\t" + to_string(joggingTrack) + "\t" + to_string(refreshment);
    }
};