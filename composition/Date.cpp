#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Date.h"

Date::Date(int mn, int dy, int yr)
{
    //Validade month
    if(mn > 0 && mn <= 12)
        month = mn;
    else //Invalid month! Are we set to 1
    {
        month = 1;
        cout << "Invalid month (" << mn << ") set to 1.\n";
    }

    year = yr;
    day = checkDay(dy);

    cout << "Date object constructor for date";
    print();
    cout << endl;
}

void Date::print() const
{
    cout << month << "/" << day << "/" << year;
}

Date::~Date()
{
    cout << "Date object constructor for date";
    print();
    cout << endl;
}

int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30,
                 31, 31, 30, 31, 30, 31};

    //Verify if testDay is valid during month
    if(testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;
    
    if(month == 2 && testDay == 29 && (year % 400 ||
      (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    cout << "Invalid day (" << testDay << ") set to 1.\n";
    return 1;//Return a valid date
}
