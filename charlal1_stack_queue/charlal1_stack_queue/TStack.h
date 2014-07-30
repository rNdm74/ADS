#pragma once

#include "StdAfx.h"
#include "Node.h"

template<class T> 
ref class TStack
{ 		

public: 
    TStack();
    void Push(T item);
    T Pop();
	T Peek();
	int Count();
	bool IsEmpty();

private:
	Node<T>^ head;
	Node<T>^ tail;	
};

template<class T> TStack<T>::TStack()
{
	head = nullptr;
	tail = nullptr;
};

template<class T> void TStack<T>::Push(T item)
{
	Node<T>^ newNode = gcnew Node<T>();
	newNode->Data = item;

	// Throws exception if item is null
	if(newNode == nullptr)
		throw gcnew StackOverflowException("You are trying to push a null item"); 

	if(tail == nullptr) // Empty list
	{
		head = newNode;
		tail = newNode;
	}
	else // Adding to head
	{
		// Set head to item->Next
		newNode->Next = head;
		head = newNode;
	}
};

template<class T> T TStack<T>::Pop()
{
	if(head == nullptr)
	{
		// Throw exeption if stack empty
		throw gcnew InvalidOperationException("Cannot pop an empty stack");
	}
	else
	{
		// Copy head to temp item
		Node<T>^ item = head;
		
		if(head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = head->Next;
		}

		item->Next = nullptr;

		// Return saved head
		return safe_cast<T>(item->Data);
	}
};

template<class T> T TStack<T>::Peek()
{
	if(head == nullptr)
	{
		// Throw exeption if stack empty
		throw gcnew InvalidOperationException("Cannot peek an empty stack");
	}
	else
	{
		return safe_cast<T>(head->Data);
	}	
};

template<class T> int TStack<T>::Count()
{
	Node<T>^ walker = head;

	int count = 0;

	while(walker != nullptr)
	{
		count++;
		walker = walker->Next;
	}

	return count;
};

template<class T> bool TStack<T>::IsEmpty()
{
	return head == nullptr;
};