#ifndef DATE_H
#define DATE_H

class Date
{
public:
    Date(int = 1, int = 1, int = 1900);//default constructor
    void print() const;//print date with format mm/dd/yyyy
    ~Date();

private:    
    int month;
    int day;
    int year;

    //Use to check if day is valid
    //Valid day with base in month and year
    int checkDay(int) const;  
};

#endif
