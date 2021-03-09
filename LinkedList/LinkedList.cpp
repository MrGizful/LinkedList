#include <iostream>
#include <iomanip>
#include "SinglyLinkedList.h"

void printList(SinglyLinkedList list, std::string comment);

int main()
{
    SinglyLinkedList test({ 1,2,3,6,9 });
    printList(test, "Start list: ");

    test.pushBack(10);
    test.pushForward(0);
    test.push(4, 5);
    printList(test, "List after push: ");

    test.popFirst();
    test.popLast();
    test.pop(2);
    printList(test, "List after pop: ");

    SinglyLinkedList searchedList;
    for (int i = 0; i < test.size(); i++)
        if (test.search(i) != -1)
            searchedList.pushBack(test[test.search(i)]);
    printList(searchedList, "New list: ");
}

void printList(SinglyLinkedList list, std::string comment)
{
    std::cout << std::setw(20) << comment;
    for (int i = 0; i < list.size(); i++)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}