#pragma once
#include <vector>
#include "SinglyLinkedListNode.h"

class SinglyLinkedList
{
	SinglyLinkedListNode* head;
	int size;

public:

	SinglyLinkedList();

	SinglyLinkedList(std::vector<int> initArray);

	SinglyLinkedList(const SinglyLinkedList& initList);

	void pushBack(int data);

	void pushForward(int data);

	void push(int data, int pos);

	int popFirst();

	int popLast();

	int pop(int pos);

	int size();

	int search(int data);

	int operator[](int pos);
};

