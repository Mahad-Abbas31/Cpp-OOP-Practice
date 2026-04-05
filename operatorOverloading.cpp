/*
-->Operator Overloading
   "In C++, we can change the way operators e.g., +, -, <, >, etc., work for
    user-defined types like objects and structures. This is known as operator
    overloading"

-> Why Use It?
    - Makes code more readable and natural
    - Lets objects behave like real-world entities
    - Improves code clarity

-> Important Rules
    - You cannot create new operators, only overload existing ones
    - Some operators cannot be overloaded, like:
        :: (scope resolution)
        . (member access)
        ?: (ternary)
        sizeof
    - At least one operand must be a user-defined type
    - The precedence of an operator is NOT affected due to overloading
    - Associativity is NOT changed due to overloading
        . Unary operators and assignment operator are right associative
    - Always write code representing the operator
        . Adding subtraction code inside the + operator will create chaos
    - Overloading << , >> operators work same for the fout and fin 
      so don't have to overload them separately.
*/

#include<iostream>
#include<fstream>

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

    // ____ (+)Overloading
    Box operator+(Box b){
        Box temp(0, 0, 0);

        temp.wid = this->wid + b.wid;
        temp.hei = this->hei + b.hei;
        temp.len = this->len + b.len;

        return temp;
    }

    // ____ (-)Overloading
    Box operator-(Box b){
        Box temp(0, 0, 0);

        temp.wid = this->wid - b.wid;
        temp.len = this->len - b.len;
        temp.hei = this->hei - b.hei;

        return temp;
    }

    // ____ (<)Overloading
    bool operator<(const Box &b){
        if(volume < b.volume)
            return true;
        
        return false;
    }

    // ____ (>)Overloading
    bool operator>(const Box &b){
        if(volume > b.volume)
            return true;
        
        return false;
    }

    /* Why are we returning ostream &?
        - It allows us to “chain” output commands together
        - And reference “&” to avoid creating new object
    */
    // ____ (<<)Stream Operator Overloading
    friend ostream &operator<<(ostream &output, const Box &b){
        output << "\nHeight: " << b.hei
               << "\n Width: " << b.wid
               << "\nLength: " << b.len << endl;
        
        return output;
    }

    // ____ (>>)Stream Operator Overloading (No const class for input)
    friend istream &operator>>(istream &input, Box &b){
        input >> b.hei >> b.wid >> b.len;
        return input;
    }
};

int Box::count = 0;

int main(){
    ofstream fout("practiceFile.txt", ios::app);

    Box b1(2, 3, 4);
    Box b2(4, 5, 2);

    if(b1<b2){
        cout << "b2 is the larger Box\n"
             << b2;
        fout << "b2 is the larger Box\n"
             << b2;
    }
    else{
        cout << "b1 is the larger Box\n"
             << b1;
        fout << "b1 is the larger Box\n"
             << b1;
    }
}