#pragma once

#include "StdAfx.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

template<typename T>
value struct Node
{
public:
	Node^ Next;
	T Data;

	virtual String^ ToString() override
    {
        return Data->ToString();
    }
};

template<class T> 
ref class PriorityQueue
{
public: 
    PriorityQueue();
    void Push(T item);
    T Pop();
	T Peek();
	int Count();
	bool IsEmpty();
	void Dump();
	

private:	
	Node<T>^ head;
	Node<T>^ tail;

	void sort(Node<T>^ %headRef);
	Node<T>^ merge(Node<T>^ %a, Node<T>^ %b);
	void split(Node<T>^ %source, Node<T>^ %headRef, Node<T>^ %tailRef);

};

/// <summary>
/// Summary for Constructor
///	
/// PRE-CONDITION:	Must provide the type of the stack
/// POST-CONDITION: The head and tail are assigned nullptr's 
/// </summary>
template<class T> PriorityQueue<T>::PriorityQueue()
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
template<class T> void PriorityQueue<T>::Push(T item)
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

		//
		sort(head);
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
template<class T> T PriorityQueue<T>::Pop()
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
template<class T> T PriorityQueue<T>::Peek()
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
template<class T> int PriorityQueue<T>::Count()
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
template<class T> bool PriorityQueue<T>::IsEmpty()
{
	return head == nullptr;
};

/// <summary>
/// Summary for Dump
///
/// PRE-CONDITION:	No change
/// POST-CONDITION: 
/// </summary>
template<class T> void PriorityQueue<T>::Dump()
{
	
	if( IsEmpty() )
	{
		Trace::WriteLine( "-empty-" );
	}	
	else 
	{	
		Trace::WriteLine( "" );

		// Set the walker at the first node
		Node<T>^ walker = head;
		
		// While not at the end node
		while( walker != nullptr )
		{
			Trace::Write( walker->ToString() + " " );
			// Move to next node
			walker = walker->Next;			
		}
	}	
};

/// <summary>
/// Summary for sort
///
/// PRE-CONDITION:	No change
/// POST-CONDITION: 
/// </summary>
template<class T> void PriorityQueue<T>::sort(Node<T>^ %headRef) 
{
	Node<T>^ a;
	Node<T>^ b;

	// Base case 
	if ((headRef == nullptr) || (headRef->Next == nullptr))
	{
		return;
	}

	// Split head into sublists
	split(headRef, a, b); 

	// Recursively sort the sublists
	sort(a);
	sort(b);

	// Merge the two sorted lists together
	headRef = merge(a, b);

	// Update Tail
	Node<T>^ walker = head;

	while(walker->Next != nullptr)
		walker = walker->Next;

	tail = walker;

};

/// <summary>
/// Summary for merge
///
/// PRE-CONDITION:	No change
/// POST-CONDITION: 
/// </summary>
template<class T> Node<T>^ PriorityQueue<T>::merge(Node<T>^ %a, Node<T>^ %b) 
{
    Node<T>^ result = nullptr;
 
	// Base cases
	if (a == nullptr)
		return b;
	else if (b == nullptr)
		return a;

	// Pick either a or b, and recurse
	// Problematic can break
	if ( b->Data->CompareTo( a->Data ) > 0 )
	{
		result = a;
		result->Next = merge( a->Next, b );
	}
	else
	{
		result = b;
		result->Next = merge( a, b->Next );
	}

	return result;
};

/// <summary>
/// Summary for split
///
/// PRE-CONDITION:	No change
/// POST-CONDITION: 
/// </summary>
template<class T> void PriorityQueue<T>::split(Node<T>^ %source, Node<T>^ %frontRef, Node<T>^ %backRef) 
{
    Node<T>^ fast;
	Node<T>^ slow;

	if (source == nullptr || source->Next == nullptr)
	{		
		frontRef = source;
		backRef = nullptr;
	}
	else
	{
		slow = source;
		fast = source->Next;

		// Advance fast two nodes, and advance slow one node
		while (fast != nullptr)
		{
			fast = fast->Next;

			if (fast != nullptr)
			{
				slow = slow->Next;
				fast = fast->Next;
			}
		}

		// Slow is before the midpoint in the list, so split it in two at that point
		frontRef = source;
		backRef = slow->Next;
		slow->Next = nullptr;
	}
};