#include <iostream>
#include <fstream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time(int h,int m,int s){
    hour=h;
    minute=m;
    second=s;
}

void Time::setTime(int h,int m,int s){
    hour=h;
    minute=m;
    second=s;
}


int Time::getHour(){    return hour;    }
int Time::getMinute(){    return minute;    }
int Time::getSecond(){    return second;    }


int Time::toSeconds(){
    return hour*3600 + minute*60 + second;
}


void Time::inputTime(){

    cout<<"Enter Hour: ";
    cin>>hour;

    cout<<"Enter Minute: ";
    cin>>minute;

    cout<<"Enter Second: ";
    cin>>second;
}


void Time::printTime(){

    cout<<setfill('0')<<setw(2)<<hour<<":"
        <<setw(2)<<minute<<":"
        <<setw(2)<<second<<endl;
}


void Time::writeToFile(){

    ofstream file("time.txt", ios::app);

    file<<hour<<" "<<minute<<" "<<second<<endl;
    file.close();
}


void Time::displayXFactor(){

    ifstream file("time.txt");

    int h,m,s;
    int maxSec=-1;
    int xh,xm,xs;

    while(file>>h>>m>>s){

        int sec = h*3600 + m*60 + s;

        if(sec>maxSec){
            maxSec=sec;
            xh=h;
            xm=m;
            xs=s;
        }
    }

    file.close();

    if(maxSec==-1)
        cout<<"No records in file\n";
    else{
        cout<<"Time with X-Factor (largest time): ";
        cout<<setfill('0')<<setw(2)<<xh<<":"
            <<setw(2)<<xm<<":"
            <<setw(2)<<xs<<endl;
    }
}