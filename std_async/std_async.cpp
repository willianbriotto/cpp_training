#include <iostream>
#include <future>
#include <functional>

template <typename T>
void print(T s1, T s2)
{
    std::async(std::launch::async, [](int i, int f) {
        for(; i < f; i++)
            std::cout << i << std::endl;
    }, s1, s2); 
}

int main()
{
    print(15, 18);
    print(18, 55);
    print(-12, -3);
}
