#include "Date.h"
#include <iostream>

using namespace std;

// ___ Static Initialization
Date Date::examDate (7,6,2021);

// ___ Constructor
    Date::Date(int day, int month, int year){
        setDay(day);
        setMonth(month);
        setYear(year);
    }

// ___ Setters
void Date::setDay(int day){        
    if(day > 0 && day <= 31)
        this->day = day;        
}

void Date::setMonth(int month){    
    if(month > 0 && month <= 12)
        this->month = month;    
}

void Date::setYear(int year){      
    if(year > 0)
        this->year = year;
}

// ___ Getters
int Date::getDay() const{          return day;      }
int Date::getMonth() const{        return month;    }
int Date::getYear() const{         return year;     }

// ___ Adders
void Date::addDay(int d){
    day = day + d;

    while(day > 31){
        day = day - 31;
        addMonth(1);
    }
}

void Date::addMonth(int m){
    month = month + m;

    while(month > 12){
        month = month - 12;
        addYear(1);
    }    
}

void Date::addYear(int year){
    this->year = this->year + year;

    if(day == 29 && month == 2 && !leapYear(this->year)){
        day = 1;
        month = 3;
    }   
}


// ___ Helper Function (Leap Year)
bool Date::leapYear(int x) const{
    if((x%4 == 0 && x%100 != 0) || (x%400==0))
        return true;

    return false;
}

// ___ Static Function
void Date::setExamDate(int aDay,int aMonth, int aYear){
    examDate.setDay(aDay);
    examDate.setMonth(aMonth);
    examDate.setYear(aYear);
}

// ___ Destructor
Date::~Date(){}