#ifndef TIME_H
#define TIME_H

class Time{
public:
    Time(int =0, int =0, int =0);

    void setTime(int, int, int);
    int getHour();
    int getMinute();
    int getSecond();

    int toSeconds();           // used for X-factor comparison

    void inputTime();
    void printTime();

    void writeToFile();
    static void displayXFactor();

private:
    int hour;
    int minute;
    int second;
};

#endif