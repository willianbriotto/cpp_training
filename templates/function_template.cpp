#include <iostream>
#include <string>

template <typename T>
inline T const& Max(T const& a, T const& b)
{
    return a < b ? b : a;
}

int main()
{
    std::cout << "Max value with int: " << Max(20, 30) << std::endl;
    std::cout << "Max value with double: " << Max(25.8, 18.7) << std::endl;
    std::cout << "Max value with string(This is coll =D): " 
         << Max("Willian", "Briotto") << std::endl;

    return 0;
}
