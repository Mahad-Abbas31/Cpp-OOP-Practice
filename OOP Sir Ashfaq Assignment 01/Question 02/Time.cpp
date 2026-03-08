#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h" 

using namespace std;

Time::Time( int hour, int minute, int second ){
    setTime( hour, minute, second ); // validate and set time
}


// ___ Setter Methods
// set new Time value using universal time
void Time::setTime( int h, int m, int s ){
    setHour( h ); // set private field hour
    setMinute(m); // set private field minute
    setSecond(s); // set private field second
}


void Time::setHour( int h ){
    if ( h >= 0 && h < 24 )
        hour = h;
    else
        throw invalid_argument( "hour must be 0-23" );
}

 
void Time::setMinute( int m ){
    if ( m >= 0 && m < 60 )
        minute = m;
    else
        throw invalid_argument( "minute must be 0-59" );
} 


void Time::setSecond( int s ){
    if ( s >= 0 && s < 60 )
        second = s;
    else
        throw invalid_argument( "second must be 0-59" );
}


// ___ Getter Methods
int Time::getHour(){    return hour;    }
int Time::getMinute(){    return minute;    }
int Time::getSecond(){    return second;    }


// ___ print Time in universal-time format (HH:MM:SS)
void Time::printUniversal(){
    cout << setfill( '0' ) << setw( 2 ) << getHour() << ":"
    << setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
}

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard(){
    cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
         << ":" << setfill( '0' ) << setw( 2 ) << getMinute()
         << ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
}

// ___ Tick Function Added
void Time::tick(){
    second++;

    if(second == 60){
        second = 0;
        minute++;

        if(minute == 60){
            minute = 0;
            hour++;

            if(hour == 24)
                hour = 0;
        }
    }
}