#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// ___ Class
class StudentReport {
private:
    string name;
    int id;
    int subjects;
    int *marks;
    
public:

    // ___ Default Constructor
    StudentReport() {
        name = "Unknown";
        id = 0;
        subjects = 0;
        marks = nullptr;
    }

    // ___ Parameterized Constructor
    StudentReport(string name, int id, int subjects) {
        this->name = name;
        this->id = id;
        this->subjects = subjects;
        this->marks = new int[subjects];

        for(int i=0; i<subjects; i++)
            this->marks[i] = i;    
    }

    // ___ Copy Constructor (Deep Copy)
    StudentReport(const StudentReport& obj) {
        id = obj.id;
        subjects = obj.subjects;
        name = obj.name;
        marks = new int[subjects];

        for (int i = 0; i < subjects; i++)
            marks[i] = obj.marks[i];
    }

    // ___ Destructor
    ~StudentReport() {
        delete[] marks;
    }

    // ___ Setter Functions
    void setName(string name) {    this->name = name;    }

    void setId(int id) {    this->id = id;    }


    void setSubjects(int subjects) {
        delete[] marks;  // delete old memory

        this->subjects = subjects;
        marks = new int[subjects];  // allocate new memory
    }

    void setMarks(int* marks, int subjects) {
        delete[] marks;

        this->subjects = subjects;
        marks = new int[subjects];

        for (int i = 0; i < subjects; i++)
            this->marks[i] = marks[i];
    }

    // ___ Getter Functions
    string getName() const{    return name;    }

    int getId(){    return id;    }

    // ___ Input Marks Function
    void inputMarks(){
        cout << "\n----Enter Marks of the Student----\n";
        for (int i = 0; i < subjects; i++){
            cout << "Subject " << i+1 << " : ";
            cin >> marks[i];
        }
        
    }

    // ___ Total Marks
    double calculateTotal() const {
        int total = 0;
        for (int i = 0; i < subjects; i++)
            total += marks[i];

        return total;
    }

    // ___ Avg Marks
    double calculateAverage() const {
        if (subjects == 0) return 0;
        return calculateTotal() / subjects;
    }

    // ___ Display Report
    void displayReport() const {
        cout << "\n--- Student Report ---\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Marks: ";
        for (int i = 0; i < subjects; i++)
            cout << marks[i] << " ";
        
        cout << "\nTotal: " << calculateTotal();
        cout << "\nAverage: " << calculateAverage() << endl;
    }

    // ___ File Output Report
    void outReport() const {
        ofstream fout("student.txt", ios::app);
        
        if (!fout) {
            cout << "File opening failed!\n";
            return;
        }
        
        fout << "\n--- Student Report ---\n";
        fout << "Name: " << name << endl;
        fout << "ID: " << id << endl;
        fout << "Marks: ";
        
        for (int i = 0; i < subjects; i++)
        fout << marks[i] << " ";
        
        fout << "\nTotal: " << calculateTotal();
        fout << "\nAverage: " << calculateAverage() << endl;
    }
};

// ___ Main Function
int main() {

    StudentReport s1("Mahad", 2501366, 4);
    s1.inputMarks();

    StudentReport s2 = s1;
    s2.setName("Hammad");
    s2.setId(2501302);
    s2.setSubjects(5);
    s2.inputMarks();

    s1.displayReport();
    s2.displayReport();

    s1.outReport();
    s2.outReport();
    return 0;
}