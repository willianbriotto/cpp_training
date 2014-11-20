#include <iostream>
#include <thread>

void printName() {
     std::cout << "Willian Briotto" << std::endl;
}

static const int n_threads = 10;

int main() {
    std::thread t[n_threads];

    //Launch various threads
    for(int i = 0; i < n_threads; i++)
        t[i] = std::thread(printName);

    std::cout << "Before this part, join the threads in main\n";

    for(int i = 0; i < n_threads; i++)
        t[i].join();

    return 0;
}
