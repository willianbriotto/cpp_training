#include <iostream>
#include <thread>
#include <string>
#include <vector>

static const int n_threads = 10;

void printName(std::string name) {
    std::cout << "Name is " << name << std::endl;
}

int main() {
    std::vector<std::string> _names = {"Willian", "João", "José", "Manoel", 
                                       "Sara", "Melissa", "Jéssica", "Marcia",
                                       "Matheus", "Aguinaldo"};
    std::thread t[n_threads];

    for(int i = 0; i < n_threads; i++) 
        t[i] = std::thread(printName, _names[i]);

    std::cout << "Launched from the main\n";

    //Join threads with the main thread
    for(int i = 0; i < n_threads; i++)
        t[i].join();

    return 0;
}
