#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

template <class T>
class Stack {
    private:
        std::vector<T> elements;

    public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const { return elements.empty(); }
};

template <class T>
void Stack<T>::push (T const& emt)
{
    elements.push_back(emt);
}

template <class T>
void Stack<T>::pop()
{
    if(elements.empty()) {
        std::cout << "This is empty" << std::endl;
        std::exit(1);
    }      
    elements.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if(elements.empty()) {
        std::cout << "This is empty" << std::endl;
        std::exit(1);
    }
    return elements.back();
}

int main() 
{
    Stack<int> stackInt;
    Stack<std::string> stringStack;

    //int Stack
    stackInt.push(7);
    std::cout << stackInt.top() << std::endl;

    //string Stack
    stringStack.push("Willian");
    std::cout << stringStack.top() << std::endl;
    stringStack.pop();
    stringStack.pop();

    return 0;
}
