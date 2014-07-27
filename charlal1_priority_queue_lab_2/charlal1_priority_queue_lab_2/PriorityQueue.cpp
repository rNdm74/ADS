#include "StdAfx.h"
#include "PriorityQueue.h"
#include "Patient.h"

namespace charlal1_priority_queue_lab_2 
{
	/// <summary>
	/// Summary for Constructor
	///	
	/// PRE-CONDITION:	Must provide a size of the queue on instantiation
	/// POST-CONDITION: A new Patient array is instantiated with a specifed size from user, three integers are created 
	///					1. stackPointerReset - sets the pointer to a default value. NOTE: This is always the last element in the array.
	///					2. stackPoint - points to the element which is return when Peek() and Pop() are called
	///					3. stackCount - keeps track of the amount of elements in the array and is used when Count() and isEmpty() are called
	/// </summary>
	PriorityQueue::PriorityQueue(int size)
	{
		// Instantiate the array
		stack = gcnew array<Patient^>(size);
		// Always the last element in the array
		stackPointerReset = size - 1;
		// Init pointer for Pop and Peek
		stackPointer = stackPointerReset;
		// Init count
		stackCounter = 0;	
	}

	
	/// <summary>
	/// Summary for Push
	///
	/// PRE-CONDITION:	Patient MUST be passed into function, there is no change to the array
	/// POST-CONDITION: A new Patient is inserted into the array, the array state and two integers will be modified
	///					1. stackCounter - integer will be incremented by 1
	///					2. stackPointer - will be reset to the stackPointerReset value
	///					Upon insertion, the array will be sorted on the priority value of the patient
	///					When a large queue is instantiated this method may take some time to add a new Patient
	/// </summary>
	void PriorityQueue::Push(Patient^ patient)
	{		
		// Throws exception if stack is full OR patient is null
		if(stackCounter >= stack->Length || patient == nullptr)
			throw gcnew StackOverflowException(); 

		// Increase number of patients in stack
		stackCounter++;

		// Reset stackPointer to end of array
		stackPointer = stackPointerReset;	

		// Find first available position in stack #inefficient method find alternative
		int firstAvailablePosition = 0;
		while(stack[firstAvailablePosition] != nullptr)
			firstAvailablePosition++;

		// Add patient to array at next avail position
		stack[firstAvailablePosition] = patient;

		// Sort array on priority number
		Array::Sort(stack);	
	}

	
	/// <summary>
	/// Summary for Pop
	///
	/// PRE-CONDITION:	No change
	/// POST-CONDITION: Two possible results, the state of the array will be modified
	///					- Next available patient will be return and is removed from the array
	///					- Exception thrown no available patients in the stack
	///					Two integers will be modified on both results
	///					1. stackCounter - will be decremented or reset to 0
	///					2. stackPoint - is decremented, pointing to the next available patient
	/// </summary>
	Patient^ PriorityQueue::Pop()
	{
		// Reduce count in stack
		stackCounter--;	  

		// Stack has patient available
		if (stackCounter >= 0) 
		{       
			// Copy patient to temp
			Patient^ nextPatient = stack[stackPointer];
			// Remove patient from stack
			stack[stackPointer] = nullptr;        
			// Move to next patient
			stackPointer--;
			// Return patient
			return nextPatient;
		}
		else // Stack empty :stackCounter = -1
		{
			stackCounter = 0; 
			// Throw exeption if stack empty
			throw gcnew InvalidOperationException("Cannot pop an empty stack");
		}
	}

	
	/// <summary>
	/// Summary for Peek
	///
	/// PRE-CONDITION:	No change
	/// POST-CONDITION: No change to the state of any variables or the array
	///					Two possible results may occur
	///					1. Next available patient will be returned
	///					2. Exception thrown no available patients in the stack
	/// </summary>
	Patient^ PriorityQueue::Peek()
	{
		// Stack has patients   
		if (stack[stackPointer] != nullptr)	
		{
			// Return last added patient in stack
			return stack[stackPointer];	
		}   
		else // Stack empty : stackCounter = -1
		{
			// Throw exeption if stack empty
			throw gcnew InvalidOperationException("Cannot peek an empty stack");	
		}
	}


	/// <summary>
	/// Summary for Count
	///
	/// PRE-CONDITION:	No change
	/// POST-CONDITION: Returns the value of stackCounter
	/// </summary>
	int PriorityQueue::Count()
	{
		return stackCounter;
	}


	/// <summary>
	/// Summary for IsEmpty
	///
	/// PRE-CONDITION:	No change
	/// POST-CONDITION: Returns a boolean if there are elements in the array
	/// </summary>
	bool PriorityQueue::IsEmpty()
	{
		return stackCounter == 0;
	}
}