#include <iostream>

using namespace std;

class Box{
    int hei;
    int wid;
    int len;
    int volume;

    static int count;

  public:
    // ____ Constructor
    Box(int len = 0, int hei = 0, int wid = 0){
        this->len = len;
        this->wid = wid;
        this->hei = hei;
        this->volume = hei * wid * len;

        count++;
    }

    // ____ Setters
    void setHei(int hei){       this->hei = hei;        }    
    void setWid(int wid){       this->wid = wid;        }
    void setLen(int len){       this->len = len;        }

    // ____ Getters
    int getHei(){       return hei;        }
    int getWid(){       return wid;        }
    int getLen(){       return len;        }
    int getVol(){       return volume;     }
    
    // ____ Display
    void display(){
        cout << "\nHeight: " << hei
             << "\n Width: " << wid
             << "\nLength: " << len << endl;
    }

    // ____ (+)Overloading (int and obj)
    friend Box operator+(Box b, int x){
        Box temp;

        temp.hei = x + b.hei;
        temp.wid = x + b.wid;
        temp.len = x + b.len;

        return temp;
    }

    // ____ (-)Overloading (int and obj)
    friend Box operator-(Box b, int x){
        Box temp;

        temp.hei = b.hei - x;
        temp.wid = b.wid - x;
        temp.len = b.len - x;

        return temp;
    }
};

int Box::count = 0;

int main(){

}