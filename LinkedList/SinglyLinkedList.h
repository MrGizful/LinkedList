#pragma once
#include <vector>
#include <stdexcept>
#include "SinglyLinkedListNode.h"

//Worst and average time complexity
//Access - O(n), Search - O(n), Insertion - O(1), Deletion - O(1)
//Worst space complexity - O(n)

class SinglyLinkedList
{
	SinglyLinkedListNode* head;
	int count;

public:

	SinglyLinkedList();

	SinglyLinkedList(std::vector<int> initArray);

	void pushBack(int data);

	void pushForward(int data);

	void push(int data, int pos);

	int popFirst();

	int popLast();

	int pop(int pos);

	int size();

	int search(int data);

	int& operator[](int pos);
};

