#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

// ___ Constructor
Time::Time(int h, int m, int s){    setTime(h, m, s);    }

bool Time::setTime(int h, int m, int s){
    if(!setHour(h)) return false;
    if(!setMinute(m)) return false;
    if(!setSecond(s)) return false;

    return true;
}

bool Time::setHour(int h){
    if(h >= 0 && h < 24){
        hour = h;
        return true;
    }
    return false;
}

bool Time::setMinute(int m){
    if(m >= 0 && m < 60){
        minute = m;
        return true;
    }
    return false;
}

bool Time::setSecond(int s){
    if(s >= 0 && s < 60){
        second = s;
        return true;
    }
    return false;
}

// ___ Getter Methods
int Time::getHour(){    return hour;    }
int Time::getMinute(){    return minute;    }
int Time::getSecond(){    return second;    }

void Time::printUniversal(){
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second;
}

void Time::printStandard(){
    
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
         << ":" << setfill('0') << setw(2) << minute
         << ":" << setw(2) << second
         << (hour < 12 ? " AM" : " PM");
}