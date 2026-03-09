#include <iostream>
#include "Time.h"

using namespace std;

int main(){

    int choice;

    do{
        cout<<"\n1. Enter Time";
        cout<<"\n2. Display Time with X-Factor";
        cout<<"\n3. Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1){

            Time t;
            char again;

            do{
                t.inputTime();
                t.writeToFile();

                cout<<"Enter more times? (y/n): ";
                cin>>again;

            }while(again=='y' || again=='Y');
        }

        else if(choice==2){

            Time::displayXFactor();
        }

    }while(choice!=3);

    return 0;
}