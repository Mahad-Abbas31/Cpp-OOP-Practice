#include <iostream>

using namespace std;

//___ Calculate Pay
struct Employee{
    int hour;
    float rate;
    float pay;
};

//___ Function Prototypes
void getData(Employee *e, const int size);
void calculatePay(Employee *e, const int size);
void displayPay(const Employee *e, const int size);

//___ Main
int main(){

    const int EmployeeNo = 2;
    Employee e[EmployeeNo];

    getData(e, EmployeeNo);

    calculatePay(e, EmployeeNo);
    
    displayPay(e, EmployeeNo);

    return 0;
}

//___ Data Input Function
void getData(Employee *e, const int size){
 
    for(int i=0; i<size; i++){
        cout << "Employee #" << i+1 << endl
        << "Rate: ";
        cin >> e[i].rate;
        
        cout << "Working Hours: ";
        cin >> e[i].hour;
        cout << "--------------------------\n";
        
    }
}

//___ Calculate Pay
void calculatePay(Employee *e, const int size){
    
    for(int i=0; i<size; i++){
        e[i].pay = e[i].rate * e[i].hour * 30;
    }
}

//___ Display Pay
void displayPay(const Employee *e, const int size){
    for(int i=0; i<size; i++){
        cout << "\nEmployee #" << i+1 << " Monthly Pay is:" << e[i].pay;
    }
}