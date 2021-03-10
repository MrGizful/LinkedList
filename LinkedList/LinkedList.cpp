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

    DoublyLinkedList testDoubly({ 11,22,35,26,19 });
    printDoublyList(testDoubly, "Initial doubly list: ");

    testDoubly.pushBack(42);
    testDoubly.pushForward(67);
    testDoubly.push(59, 4);
    printDoublyList(testDoubly, "Doubly list after push: ");

    testDoubly.popFirst();
    testDoubly.popLast();
    testDoubly.pop(2);
    printDoublyList(testDoubly, "Doubly list after pop: ");

    DoublyLinkedList searchedDoublyList;
    for (int i = 0; i < testDoubly.size(); i++)
        if (testDoubly.search(10 * i + i) != -1)
            searchedDoublyList.pushBack(testDoubly[testDoubly.search(10 * i + i)]);
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