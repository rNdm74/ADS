#pragma once

#include "StdAfx.h"
#include "Node.h"

template<class T> 
ref class TQueue
{    
public: 
    TQueue();
    void Push(T item);
    T Pop();
	T Peek();
	int Count();
	bool IsEmpty();

private:
	Node<T>^ head;
	Node<T>^ tail;	
};

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	Must provide the type of the stack
/// POST-CONDITION: The head and tail are assigned nullptr's 
/// </summary>
template<class T> TQueue<T>::TQueue()
{
	head = nullptr;
	tail = nullptr;
};

/// <summary>
/// Summary for Push
///
/// PRE-CONDITION:	variable MUST be passed into function
/// POST-CONDITION: A new node is created, head and tail may be modified, two possible outcomes
///					1. stack is empty, the head and tail are assigned the new node
///					2. stack has nodes, the newNode is added to the tail->Next pointer,
///					   the newNode is assigned to the tail
/// </summary>
template<class T> void TQueue<T>::Push(T item)
{
	// Create node to hold data 
	// We do not care what data is added
	Node<T>^ newNode = gcnew Node<T>();
	newNode->Data = item;

	// Empty list
	if(tail == nullptr)			
	{
		// Only one node in stack
		head = newNode;
		tail = newNode;
	}
	else						
	{
		// Set tail to newNode->Next
		tail->Next = newNode;
		tail = newNode;
	}
};

/// <summary>
/// Summary for Pop
///
/// PRE-CONDITION:	No change
/// POST-CONDITION: Two possible results, state of the linked nodes may change
///					1. Returns data from head node
///					2. Exception thrown if stack empty
///					If stack has items, the second node will be made the head node
///					Else if the last node in the stack the head and tail will be reset
/// </summary>
template<class T> T TQueue<T>::Pop()
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

		// Only one node in the list
		if(head == tail)
		{
			// Reset head and tail
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			// Move head to second node in list
			head = head->Next;
		}

		// Clear the next value (Not really needed)
		item->Next = nullptr;

		// Return saved head data
		return safe_cast<T>(item->Data);
	}
};

/// <summary>
/// Summary for Peek
///
/// PRE-CONDITION:	No change
/// POST-CONDITION: No change to the state of any variables or the array
///					Two possible results may occur
///					1. Returns data from head node
///					2. Exception thrown if stack empty
/// </summary>
template<class T> T TQueue<T>::Peek()
{
	if(head == nullptr)
	{
		// Throw exeption if stack empty
		throw gcnew InvalidOperationException("Cannot peek an empty queue");
	}
	else
	{
		return safe_cast<T>(head->Data);
	}	
};

/// <summary>
/// Summary for Count
///
/// PRE-CONDITION:	No change
/// POST-CONDITION: Returns the number of linked nodes
/// </summary>
template<class T> int TQueue<T>::Count()
{
	// Set the walker at the first node
	Node<T>^ walker = head;

	// Set count to zero
	int count = 0;

	// While not at the end node
	while(walker != nullptr)
	{
		// Increment count and then
		count++;
		// Move to next node
		walker = walker->Next;
	}

	return count;
};

/// <summary>
/// Summary for IsEmpty
///
/// PRE-CONDITION:	No change
/// POST-CONDITION: Returns a boolean if head is null
/// </summary>
template<class T> bool TQueue<T>::IsEmpty()
{
	return head == nullptr;
};