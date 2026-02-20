#include <iostream>
#include <cstring>

using namespace std;

// ___ Class
class StudentReport {
private:
    char* name;
    int rollNumber;
    int subjects;
    int* marks;

public:

    // ___ Default Constructor
    StudentReport() {
        name = new char[8];
        strcpy(name, "Unknown");
        rollNumber = 0;
        subjects = 0;
        marks = nullptr;
    }

    // ___ Parameterized Constructor
    StudentReport(const char* n, int roll, int sub, int* m) {
        rollNumber = roll;
        subjects = sub;

        name = new char[strlen(n) + 1];
        strcpy(name, n);

        marks = new int[subjects];
        for (int i = 0; i < subjects; i++) {
            marks[i] = m[i];
        }
    }

    // ___ Copy Constructor (Deep Copy)
    StudentReport(const StudentReport& obj) {
        rollNumber = obj.rollNumber;
        subjects = obj.subjects;

        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);

        marks = new int[subjects];
        for (int i = 0; i < subjects; i++) {
            marks[i] = obj.marks[i];
        }
    }

    // ___ Destructor
    ~StudentReport() {
        delete[] name;
        delete[] marks;
    }

    // ___ Setter Functions
    void setName(const char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setRollNumber(int rollNumber) {
        this->rollNumber = rollNumber;
    }

    void setMarks(int* m, int sub) {
        delete[] marks;
        subjects = sub;
        marks = new int[subjects];
        for (int i = 0; i < subjects; i++) {
            marks[i] = m[i];
        }
    }

    // ___ Getter Functions
    const char* getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    double calculateTotal() const {
        int total = 0;
        for (int i = 0; i < subjects; i++) {
            total += marks[i];
        }
        return total;
    }

    double calculateAverage() const {
        if (subjects == 0) return 0;
        return calculateTotal() / subjects;
    }

    // ___ Display Report
    void displayReport() const {
        cout << "\n--- Student Report ---\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: ";
        for (int i = 0; i < subjects; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nTotal: " << calculateTotal();
        cout << "\nAverage: " << calculateAverage() << endl;
    }
};

// ___ Main Function
int main() {

    int marks1[] = {85, 90, 98};

    StudentReport s1("Mahad", 101, 3, marks1);
    s1.displayReport();

    StudentReport s2 = s1;
    s2.setName("Ali");

    cout << "\nAfter Copy Constructor:\n";
    s2.displayReport();

    return 0;
}