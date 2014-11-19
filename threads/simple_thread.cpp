//For compile this code with g++ user:
//g++ -std=c++0x -pthread simple_thread.cpp
#include <iostream>
#include <thread>

//Function call by thread
void printName() {
    std::cout << "Willian Briotto" << std::endl;
}

int main() {
    //Create a thread
    std::thread myThread(printName);
    //Now, lets join the thread with the main thread
    myThread.join();

   return 0;
}
