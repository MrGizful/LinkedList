#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	count = 0;
	head = NULL;
	tail = NULL;
}

DoublyLinkedList::DoublyLinkedList(std::vector<int> initArray)
{
	for (int i = 0; i < initArray.size(); i++)
		pushBack(initArray[i]);
}

void DoublyLinkedList::pushBack(int data)
{
	if (tail != NULL)
	{
		tail->next = new DoublyLinkedListNode();
		tail->next->data = data;
		tail->next->next = NULL;
		tail->next->previous = tail;
		tail = tail->next;
	}
	else
	{
		head = tail = new DoublyLinkedListNode();
		head->next = head->previous = NULL;
		head->data = data;
	}

	count++;
}

void DoublyLinkedList::pushForward(int data)
{
	if (head != NULL)
	{
		DoublyLinkedListNode* newHead = new DoublyLinkedListNode();
		newHead->previous = NULL;
		newHead->next = head;
		newHead->data = data;
		head = newHead;
	}
	else
	{
		head = tail = new DoublyLinkedListNode();
		head->next = head->previous = NULL;
		head->data = data;
	}

	count++;
}

void DoublyLinkedList::push(int data, int pos)
{
	if (pos >= 0 && pos <= count)
	{
		if (pos == 0)
		{
			pushForward(data);
		}
		else if(pos == count)
		{
			pushBack(data);
		}
		else
		{

			DoublyLinkedListNode* current = head;
			for (int i = 0; i < pos; i++)
				current = current->next;

			DoublyLinkedListNode* insert = new DoublyLinkedListNode();
			insert->next = current;
			insert->previous = current->previous;
			insert->data = data;
			current->previous = insert;
			insert->previous->next = insert;

			count++;
		}
	}
	else
	{
		throw std::out_of_range("Element is out of range");
	}
}

int DoublyLinkedList::popFirst()
{
	if (head != NULL)
	{
		int data = head->data;
		DoublyLinkedListNode* newHead = head->next;
		
		if (newHead != NULL)
		{
			newHead->previous = NULL;
		}
		else
		{
			tail = NULL;
		}

		delete head;
		head = newHead;

		count--;

		return data;
	}
	else
	{
		throw std::underflow_error("List is empty");
	}
}

int DoublyLinkedList::popLast()
{
	if (tail != NULL)
	{
		int data = tail->data;
		DoublyLinkedListNode* newTail = tail->previous;

		if (newTail != NULL)
		{
			newTail->next = NULL;
		}
		else
		{
			head = NULL;
		}

		delete tail;
		tail = newTail;

		count--;

		return data;
	}
	else
	{
		throw std::underflow_error("List is empty");
	}
}

int DoublyLinkedList::pop(int pos)
{
	if (pos >= 0 && pos < count)
	{
		if (pos == 0)
		{
			return popFirst();
		}
		else if (pos == count - 1)
		{
			return popLast();
		}
		else
		{
			DoublyLinkedListNode* current = head;
			for (int i = 0; i < pos; i++)
				current = current->next;

			int data = current->data;
			current->previous->next = current->next;
			current->next->previous = current->previous;
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

int DoublyLinkedList::size()
{
	return count;
}

int DoublyLinkedList::search(int data)
{
	DoublyLinkedListNode* current = head;
	int index = 0;
	while (current != NULL)
	{
		if (current->data == data) return index;

		current = current->next;
		index++;
	}

	return -1;
}

int& DoublyLinkedList::operator[](int pos)
{
	if (pos >= 0 && pos < count)
	{
		DoublyLinkedListNode* current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;

		return current->data;
	}
	else
	{
		throw std::out_of_range("Element is out of range");
	}
}