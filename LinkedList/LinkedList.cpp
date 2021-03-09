#include <iostream>
#include <list>

int main()
{
    std::list<int> test;
    test.push_back(5);
    test.pop_back();
    std::cout << "Hello World!\n";
}