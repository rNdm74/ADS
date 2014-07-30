#pragma once

#include "StdAfx.h"

template<class T, int i> 
ref class TStack
{
	private:
	//T^ pStack;
	//T StackBuffer[i];
	//static const int cItem = i * sizeof(T);
	T^ head;
	T^ tail;
    
public: 
    TStack();
    void Push(T^ item);
    T^ Pop();
	T^ Peek();
	int Count();
	bool IsEmpty();

	
};

template<class T, int i> TStack<T, i>::TStack()
{
	head = nullptr;
	tail = nullptr;
};

template<class T, int i> void TStack<T, i>::Push(T^ item)
{
	if(tail == nullptr)			// Empty list
	{
		head = item;
		tail = item;

	}
	else						// Adding to end
	{
		tail->Next = item;
		tail = item;
	}
};

template<class T, int i> T^ TStack<T, i>::Pop()
{
};

template<class T, int i> T^ TStack<T, i>::Peek()
{
};

template<class T, int i> int TStack<T, i>::Count()
{

	Node^ nodeWalker = head;

	int count = 0;

	while(nodeWalker != nullptr)
	{
		count++;
		nodeWalker = nodeWalker->Next;
	}

	return count;
};

template<class T, int i> bool TStack<T, i>::IsEmpty()
{
};