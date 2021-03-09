#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
	count = 0;
	head = NULL;
}

SinglyLinkedList::SinglyLinkedList(std::vector<int> initArray)
{
	for (int i = 0; i < initArray.size(); i++)
		pushBack(initArray[i]);
}

void SinglyLinkedList::pushBack(int data)
{
	if (head == NULL)
	{
		head = new SinglyLinkedListNode();
		head->data = data;
		head->next = NULL;
	}
	else
	{
		SinglyLinkedListNode* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = new SinglyLinkedListNode();
		current = current->next;
		current->data = data;
		current->next = NULL;
	}

	count++;
}

void SinglyLinkedList::pushForward(int data)
{
	if (head == NULL)
	{
		head = new SinglyLinkedListNode();
		head->data = data;
		head->next = NULL;
	}
	else
	{
		SinglyLinkedListNode* newHead = new SinglyLinkedListNode();
		newHead->data = data;
		newHead->next = head;
		head = newHead;
	}

	count++;
}

void SinglyLinkedList::push(int data, int pos)
{
	if (pos >= 0 && pos <= count)
	{
		SinglyLinkedListNode* current = head;
		SinglyLinkedListNode* previous = NULL;
		for (int i = 0; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}

		if (previous != NULL)
		{
			previous->next = new SinglyLinkedListNode();
			previous->next->data = data;
			previous->next->next = current;

			count++;
		}
		else
		{
			pushForward(data);
		}
	}
}

int SinglyLinkedList::popFirst()
{
	if (count > 0)
	{
		int data = head->data;
		SinglyLinkedListNode* newHead = head->next;

		delete head;
		head = newHead;

		count--;

		return data;
	}
	else
	{
		throw std::range_error("List is empty");
	}
}

int SinglyLinkedList::popLast()
{
	if (count > 0)
	{
		SinglyLinkedListNode* current = head;
		SinglyLinkedListNode* previous = NULL;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}

		if (previous != NULL)
			previous->next = NULL;

		int data = current->data;
		delete current;

		count--;

		return data;
	}
	else
	{
		throw std::range_error("List is empty");
	}
}

int SinglyLinkedList::pop(int pos)
{
	if (pos >= 0 && pos < count)
	{
		if (pos == 0)
		{
			return popFirst();
		}
		else if(pos == count - 1)
		{
			return popLast();
		}
		else
		{
			SinglyLinkedListNode* current = head;
			SinglyLinkedListNode* previous = NULL;
			for (int i = 0; i < pos; i++)
			{
				previous = current;
				current = current->next;
			}

			int data = current->data;
			previous->next = current->next;
			delete current;

			count--;

			return data;
		}
	}
	else
	{
		throw std::out_of_range("Element is out of range");
	}
}

int SinglyLinkedList::size()
{
	return count;
}

int SinglyLinkedList::search(int data)
{
	SinglyLinkedListNode* current = head;
	int index = 0;
	while (current != NULL)
	{
		if (current->data == data) return index;
		current = current->next;
		index++;
	}

	return -1;
}

int& SinglyLinkedList::operator[](int pos)
{
	if (pos >= 0 && pos < count)
	{
		SinglyLinkedListNode* current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;

		return current->data;
	}
	else
	{
		throw std::out_of_range("Element is out of range");
	}
}