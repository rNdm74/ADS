#pragma once

#include "StdAfx.h"

template<class T> 
ref class TStack
{    
public: 
    TStack();
    void Push(T^ item);
    T^ Pop();
	T^ Peek();
	int Count();
	bool IsEmpty();

private:
	T^ head;
	T^ tail;	
};

template<class T> TStack<T>::TStack()
{
	head = nullptr;
	tail = nullptr;
};

template<class T> void TStack<T>::Push(T^ item)
{
	// Throws exception if item is null
	if(item == nullptr)
		throw gcnew StackOverflowException("You are trying to push a null item"); 

	if(tail == nullptr)			// Empty list
	{
		head = item;
		tail = item;
	}
	else						// Adding to end
	{
		// Set head to item
		item->Next = head;

		head = item;

		// move current head to tail
		//tail->Next = item;
		//tail = item;
	}
};

template<class T> T^ TStack<T>::Pop()
{
	if(head == nullptr)
	{
		// Throw exeption if stack empty
		throw gcnew InvalidOperationException("Cannot pop an empty stack");
	}
	else
	{
		// Copy head to temp item
		T^ item = head;
		
		head = head->Next;

		// Return saved head
		return item;
	}
};

template<class T> T^ TStack<T>::Peek()
{
	if(head == nullptr)
	{
		// Throw exeption if stack empty
		throw gcnew InvalidOperationException("Cannot peek an empty stack");
	}
	else
	{
		return head;
	}	
};

template<class T> int TStack<T>::Count()
{
	T^ walker = head;

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