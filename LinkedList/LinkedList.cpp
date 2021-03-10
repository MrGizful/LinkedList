#include <iostream>
#include <iomanip>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

void printSinglyList(SinglyLinkedList list, std::string comment);
void printDoublyList(DoublyLinkedList list, std::string comment);

int main()
{
    SinglyLinkedList testSingle({ 1,2,3,6,9 });
    printSinglyList(testSingle, "Initial singly list: ");

    testSingle.pushBack(10);
    testSingle.pushForward(0);
    testSingle.push(4, 5);
    printSinglyList(testSingle, "Singly list after push: ");

    testSingle.popFirst();
    testSingle.popLast();
    testSingle.pop(2);
    printSinglyList(testSingle, "Singly list after pop: ");

    SinglyLinkedList searchedSinglyList;
    for (int i = 0; i < testSingle.size(); i++)
        if (testSingle.search(i) != -1)
            searchedSinglyList.pushBack(testSingle[testSingle.search(i)]);
    printSinglyList(searchedSinglyList, "New singly list: ");

    std::cout << std::endl;

    DoublyLinkedList testDouble({ 11,22,35,26,19 });
    printDoublyList(testDouble, "Initial doubly list: ");

    testDouble.pushBack(42);
    testDouble.pushForward(67);
    testDouble.push(59, 4);
    printDoublyList(testDouble, "Doubly list after push: ");

    testDouble.popFirst();
    testDouble.popLast();
    testDouble.pop(2);
    printDoublyList(testDouble, "Doubly list after pop: ");

    DoublyLinkedList searchedDoublyList;
    for (int i = 0; i < testDouble.size(); i++)
        if (testDouble.search(10 * i + i) != -1)
            searchedDoublyList.pushBack(testDouble[testDouble.search(10 * i + i)]);
    printDoublyList(searchedDoublyList, "New doubly list: ");
}

void printSinglyList(SinglyLinkedList list, std::string comment)
{
    std::cout << std::setw(25) << comment;
    for (int i = 0; i < list.size(); i++)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}

void printDoublyList(DoublyLinkedList list, std::string comment)
{
    std::cout << std::setw(25) << comment;
    for (int i = 0; i < list.size(); i++)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}