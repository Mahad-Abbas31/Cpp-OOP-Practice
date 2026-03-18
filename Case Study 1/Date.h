/*Design a class date through which user must be able to perform
following operations

  -> Get and set current day, month and year
  -> Increment by X number of days, months and year
  -> Set Exam date

*/

#ifndef DATE_H
#define DATE_H

class Date{
  private:
    int day;
    int month;
    int year;

    static Date examDate;

    bool leapYear(int x) const;
    
  public:
    // ___ Constructor
    Date(int aDay = 0, int aMonth= 0, int aYear= 0);
    
    // ___ Destructor
    ~Date();
    
    // ___ Setters
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    // ___ Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // ___ Adders
    void addDay(int day);
    void addMonth(int month);
    void addYear(int year);

    // ___ Static Function
    static void setExamDate(int Day,int Month, int Year);
};

#endif