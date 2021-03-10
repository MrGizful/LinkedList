#pragma once
#include <vector>
#include <stdexcept>
#include "DoublyLinkedListNode.h"

class DoublyLinkedList
{
	int count;
	DoublyLinkedListNode* head;
	DoublyLinkedListNode* tail;

public:

	DoublyLinkedList();

	DoublyLinkedList(std::vector<int> initArray);

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

