#include <iostream>
using std::cout;
using std::endl;

#include "Employee.h"

int main()
{
    Date birth(4, 22, 1993);
    Date hire(1, 7, 2014);
    Employee manager("Willian", "Briotto", birth, hire);

    cout << endl;
    manager.print();
    
    cout << "\nTest Date of constructor with invalid values:\n";
    Date lastDayOff(14, 35, 1994);//Wrong values
    cout << endl;
    return 0;
}
