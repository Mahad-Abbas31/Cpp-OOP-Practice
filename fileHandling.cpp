#include<iostream>
#include<fstream>

using namespace std;

class Student{
    string name;
    int quiz1;
    int quiz2;
    int mids;
    int finals;
    
    public:
    static Student TOP;

    Student(string n="", int q1=0, int q2=0, int m=0, int f=0){
        name = n;
        quiz1 = q1;
        quiz2 = q2;
        mids = m;
        finals = f;
    }

    void setName(string n){         name = n;        }
    void setQ1(int q){              quiz1 = q;       }    
    void setQ2(int q){              quiz2 = q;       }
    void setMids(int m){            mids = m;        }
    void setFinals(int f){          finals = f;      }

    string getName(){           return name;         }
    int getQ1(){                return quiz1;        }
    int getQ2(){                return quiz2;        }
    int getMids(){              return mids;         }
    int getFinals(){            return finals;       }

    friend ostream &operator<<(ostream &output, const Student s){
        output << "Name: " << s.name
               << "\nQuiz1: " << s.quiz1
               << "\nQuiz2: " << s.quiz2
               << "\nMids: " << s.mids
               << "\nFinals: " << s.finals << endl;
        
        return output;
    }
};

Student Student::TOP("Mahad", 10, 10, 48, 98);

int main(){
    int count = 0;

    string n;
    int q1, q2, m, f;

    ifstream fin("student.txt");

    if(!fin)
        cout << "ERROR! File could not Open.....\n";
    
    while(getline(fin, n))
        count++;

    // ✅ Reset file
    fin.clear();        // ____ Clear the EOF Marker of the file that is making the stream operator dead or unusable
    fin.seekg(0);       // ____ Move File Pointer to Start Position
    
    Student *s = new Student[count];
    
    for(int i=0; i<count; i++){
        fin >> n >> q1 >> q2 >> m >> f;
        s[i].setName(n);
        s[i].setQ1(q1);
        s[i].setQ2(q2);
        s[i].setMids(m);
        s[i].setFinals(f);
    }

    for(int i=0; i<count; i++)
        cout << s[i] << endl;

    delete[] s;
    return 0;
}
