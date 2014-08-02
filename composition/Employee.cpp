#include <iostream>
using std::cout;
using std::endl;

#include <cstring> //prototype strlen strncpy
using std::strlen;
using std::strncpy;

#include "Employee.h"
#include "Date.h"

Employee::Employee(const char * const frist, const char * const last, const Date &dateOfBirth, const Date &dateOfHire)
    : birthDate(dateOfBirth),
      hireDate(dateOfHire)
{
    int length = strlen(frist);
    length = (length < 25 ? length : 24);
    strncpy(fristName, frist, length);
    fristName[length] = '\0';

    length = strlen(last);
    length = (length < 25 ? length : 24);
    strncpy(lastName, last, length);
    lastName[length] = '\0';


    cout << "Employee object constructor: " << fristName << ' ' << lastName << endl; 
}

void Employee::print() const
{
    cout << lastName << ", " << fristName << " Hired: ";
    hireDate.print();
    cout << "Birthday: ";
    birthDate.print();
    cout << endl;
}

Employee::~Employee()
{
    cout << "Employee object constructor: " << lastName << ", " << fristName << endl; 
}
